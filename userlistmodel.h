#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "card_struct.h"

class userListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit userListModel(QObject *parent = nullptr);
    ~userListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool appendCard(card_struct card);
    bool removeCard(int index);
    const card_struct getCard(int index) const;

    void setCardList(QList<card_struct> cardList);
    void clear();
    int contains(const card_struct &card) const;

private:
    QList<card_struct> m_cardList;
};

#endif // USERLISTMODEL_H
