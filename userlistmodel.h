#ifndef UserListModel_H
#define UserListModel_H

#include <QAbstractTableModel>
#include <QList>

#include "card_struct.h"

class UserListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit UserListModel(QObject *parent = nullptr);
    ~UserListModel() = default;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool appendCard(const card_struct& card);
    bool removeCard(int index);
    const card_struct getCard(int index) const;

    void setCardList(QList<card_struct> cardList);
    void clear();
    int contains(const card_struct &card) const;

    void updatePossibleListFromFeatureCard(const card_struct &featureCard);
    void updatePossibleListFromNoFeatureCard(const card_struct &featureCard);
    void updatePossibleListFromExceptCard(const card_struct &featureCard);

private:
    QList<card_struct> m_cardList;
};

#endif // UserListModel_H
