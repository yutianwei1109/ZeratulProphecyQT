#include "UserListModel.h"

#include <QMessageBox>

UserListModel::UserListModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_cardList()
{

}

int UserListModel::rowCount(const QModelIndex &parent) const {
    if(parent.isValid()) {
        return 0;
    }
    return m_cardList.size();
}

QVariant UserListModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid()) {
        return QVariant();
    }
    if(index.row() >= m_cardList.size()) {
        return QVariant();
    }
    if(role == Qt::DisplayRole) {
        return QString::fromStdString(m_cardList[index.row()].toString());
    }
    return QVariant();
}

bool UserListModel::appendCard(const card_struct& card) {
    beginInsertRows(QModelIndex(), m_cardList.size(), m_cardList.size());
    m_cardList.push_back(card);
    endInsertRows();
    return true;
}

bool UserListModel::removeCard(int index) {
    if(index < 0 || index >= m_cardList.size()) {
        return false;
    }
    beginRemoveRows(QModelIndex(), index, index);
    m_cardList.erase(m_cardList.begin() + index);
    endRemoveRows();
    return true;
}

const card_struct UserListModel::getCard(int index) const {
    if(index < 0 || index >= m_cardList.size()) {
        return card_struct();
    }
    return m_cardList[index];
}

void UserListModel::setCardList(QList<card_struct> cardList) {
    beginResetModel();
    m_cardList = cardList;
    endResetModel();
}

void UserListModel::clear() {
    beginResetModel();
    m_cardList.clear();
    endResetModel();
}

int UserListModel::contains(const card_struct &card) const {
    return m_cardList.count(card);
}

void userListModel::updatePossibleListFromFeatureCard(const card_struct &featureCard) {
    const QString& race = featureCard.m_race;
    int number = featureCard.m_number;
    int power = featureCard.m_power;
    QList<card_struct> rmList;
    for(auto cit = pm_list->begin(); cit != pm_list->end(); cit++) {
        card_struct& card = *cit;
        if(card.m_race != race && card.m_number != number && (card.m_power < power - 200 || card.m_power > power + 200)) {
            rmList.append(card);
        } 
    }
    for(auto rit = rmList.begin(); rit != rmList.end(); rit++) {
        removeData(index(pm_list->indexOf(*rit)));
    }
}
void userListModel::updatePossibleListFromNoFeatureCard(const card_struct &noFeatureCard) {
    const QString& race = noFeatureCard.m_race;
    int number = noFeatureCard.m_number;
    int power = noFeatureCard.m_power;
    QList<card_struct> rmList;
    for(auto cit = pm_list->begin(); cit != pm_list->end(); cit++) {
        card_struct& card = *cit;
        if(card.m_race == race || card.m_number == number || (card.m_power > power - 200 && card.m_power < power + 200)) {
            rmList.append(card);
        } 
    }
    for(auto rit = rmList.begin(); rit != rmList.end(); rit++) {
        removeData(index(pm_list->indexOf(*rit)));
    }
}
void userListModel::updatePossibleListFromExceptCard(const card_struct &exceptCard) {
    removeData(index(pm_list->indexOf(exceptCard)));
}
