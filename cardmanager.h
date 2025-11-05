#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include "card_struct.h"
#include <QList>
#include <QString>
#include <array>

enum class userListIndex{
    FEATURE,
    NOFEATURE,
    EXCEPT,
    POSSIBLE,
    UNDEFINED
};

class CardManager: public QObject
{
    Q_OBJECT

public:
    CardManager(QObject *parent = nullptr);

    inline int index(userListIndex listIndex);
    // Reset
    bool init();
    void reset();
    // get
    const QList<card_struct>& getAllCards();
    QList<card_struct>& getUserList(userListIndex listIndex);
    // add
    void addCardToUserList(userListIndex listIndex, const card_struct& card);
    // search
    QList<card_struct>::const_iterator findCardInUserList(userListIndex listIndex, const int id);
    QList<card_struct>::const_iterator findCardInUserList(userListIndex listIndex, const QString& name);
    inline int cardIndexOfUserList(userListIndex listIndex, const int id);
    inline int cardIndexOfUserList(userListIndex listIndex, const QString& name);
    // remove
    bool rmCardFromUserList(userListIndex listIndex, QList<card_struct>::const_iterator cit);
    bool rmCardFromUserList(userListIndex listIndex, const int id);
    bool rmCardFromUserList(userListIndex listIndex, const QString& name);
    // remove multi
    int rmCardFromUserList(userListIndex listIndex, QList<int> idList);
    int rmCardFromUserList(userListIndex listIndex, QList<QString> nameList);

private:
    bool loadFromSource();

    QList<card_struct> m_allCards;
    std::array<QList<card_struct>, 4> m_userList;
};

#endif // CARDMANAGER_H
