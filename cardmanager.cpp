#include "cardmanager.h"
#include <QDebug>
#include <algorithm>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <iterator>

CardManager::CardManager(QObject *parent)
    :QObject(parent)
    ,m_allCards(QList<card_struct>{})
    ,m_userList(std::array<QList<card_struct>, 4>{})
{
}

int CardManager::index(userListIndex listIndex)
{
    return static_cast<int>(listIndex);
}
// Reset
bool CardManager::init()
{
    if (loadFromSource() == false) return false;
    reset();
    return true;
}
void CardManager::reset()
{
    for(auto& ulist : m_userList) {
        ulist.clear();
    }
    m_userList[index(userListIndex::POSSIBLE)] = m_allCards;
}
// get
const QList<card_struct>& CardManager::getAllCards()
{
    return m_allCards;
}
QList<card_struct>& CardManager::getUserList(userListIndex listIndex)
{
    return m_userList[index(listIndex)];
}
// add
void CardManager::addCardToUserList(userListIndex listIndex, const card_struct& card)
{
    m_userList[index(listIndex)].append(card);
}
// search
QList<card_struct>::const_iterator CardManager::findCardInUserList(userListIndex listIndex, const int id)
{
    const auto& ulist = m_userList[index(listIndex)];
    return std::find_if(ulist.begin(), ulist.end(), [id](const card_struct& card){
        return id == card.m_id;
    });
}
QList<card_struct>::const_iterator CardManager::findCardInUserList(userListIndex listIndex, const QString& name)
{
    const auto& ulist = m_userList[index(listIndex)];
    return std::find_if(ulist.begin(), ulist.end(), [name](const card_struct& card){
        return name == card.m_name;
    });
}
int CardManager::cardIndexOfUserList(userListIndex listIndex, const int id) {
    const auto& ulist = m_userList[index(listIndex)];
    auto cit = findCardInUserList(listIndex, id);
    if(cit == ulist.end()) return -1;
    return std::distance(ulist.begin(), cit);
}
int CardManager::cardIndexOfUserList(userListIndex listIndex, const QString& name) {
    const auto& ulist = m_userList[index(listIndex)];
    auto cit = findCardInUserList(listIndex, name);
    if(cit == ulist.end()) return -1;
    return std::distance(ulist.begin(), cit);
}
// remove
bool CardManager::rmCardFromUserList(userListIndex listIndex, QList<card_struct>::const_iterator cit)
{
    auto& ulist = m_userList[index(listIndex)];
    return ulist.removeOne(*cit);
}
bool CardManager::rmCardFromUserList(userListIndex listIndex, const int id)
{
    auto& ulist = m_userList[index(listIndex)];
    auto cit = findCardInUserList(listIndex, id);
    return ulist.removeOne(*cit);
}
bool CardManager::rmCardFromUserList(userListIndex listIndex, const QString& name)
{
    auto& ulist = m_userList[index(listIndex)];
    auto cit = findCardInUserList(listIndex, name);
    return ulist.removeOne(*cit);
}
// remove multi
int CardManager::rmCardFromUserList(userListIndex listIndex, QList<int> idList)
{
    auto& ulist = m_userList[index(listIndex)];
    int cnt = 0;
    for(auto id : idList) {
        auto cit = findCardInUserList(listIndex, id);
        if(cit == ulist.end()) continue;
        ulist.removeOne(*cit);
        cnt++;
    }
    return cnt;
}
int CardManager::rmCardFromUserList(userListIndex listIndex, QList<QString> nameList)
{
    auto& ulist = m_userList[index(listIndex)];
    int cnt = 0;
    for(auto name : nameList) {
        auto cit = findCardInUserList(listIndex, name);
        if(cit == ulist.end()) continue;
        ulist.removeOne(*cit);
        cnt++;
    }
    return cnt;
}

//private:
bool CardManager::loadFromSource()
{
    QFile fp(":/data/core.csv");
    if(!(fp.open(QIODevice::ReadOnly | QIODevice::Text))) {
        qDebug() << "File core.csv open failed:" << fp.errorString();
        return false;
    }

    QTextStream in(&fp);
    QString title = in.readLine();
    if(title.isEmpty()) {
        qDebug() << "Empty file or missing title.";
        fp.close();
        return false;
    }

    int cnt = 0;
    int lineNum = 2;
    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) continue;

        QStringList cols = line.split(',');
        if(cols.size() != 6) {
            qDebug() << "Invaild data columns: " << cols.size() << " in line " << lineNum;
            lineNum++;
            continue;
        }

        bool ok1, ok2, ok3, ok4;
        int id = cols[0].trimmed().toInt(&ok1);
        int star = cols[1].trimmed().toInt(&ok2);
        int number = cols[4].trimmed().toInt(&ok3);
        int power = cols[5].trimmed().toInt(&ok4);

        if(!ok1 || !ok2 || !ok3 || !ok4) {
            qDebug() << "Invalid number format in line " << lineNum;
            lineNum++;
            continue;
        }

        card_struct info(
                    id,
                    star,
                    cols[2].trimmed(),
                    cols[3].trimmed(),
                    number,
                    power
                    );

        bool isValid = true;
        if(info.m_id < 1) {
            qDebug() << "Invalid ID in line " << lineNum;
            isValid = false;
        }
        if(info.m_star < 0 || info.m_star > 7) {
            qDebug() << "Invalid star in line " << lineNum;
            isValid = false;
        }
        if(!ruleSets::cardRaces.contains(info.m_race)) {
            qDebug() << "Invalid race in line " << lineNum;
            isValid = false;
        }
        if(info.m_name.length() < 1) {
            qDebug() << "Empty name in line " << lineNum;
            isValid = false;
        }
        if(info.m_number < 0 || info.m_power < 0) {
            qDebug() << "Invalid number/power in line " << lineNum;
            isValid = false;
        }

        if(!isValid) {
            lineNum++;
            continue;
        }

        m_allCards.append(info);
        cnt++;
        lineNum++;
    }

    fp.close();
    if(cnt == 0) {
        qDebug() << "No valid card data loaded";
        return false;
    }

    qDebug() << "Successfully loaded " << cnt << " cards";
    return true;
}
