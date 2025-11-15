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

bool UserListModel::removeCard(const card_struct& card) {
    int index = m_cardList.indexOf(card);
    if(index < 0 || index >= m_cardList.size()) {
        return false;
    }
    return removeCard(index);
}

const card_struct UserListModel::getCard(int index) const {
    if(index < 0 || index >= m_cardList.size()) {
        return card_struct();
    }
    return m_cardList[index];
}

const QList<card_struct>& UserListModel::getCardList() const {
    return m_cardList;
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
