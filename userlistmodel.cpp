#include "userlistmodel.h"

#include <QMessageBox>

userListModel::userListModel(QObject *parent
    , CardManager *manager
    , userListIndex listIndex)
    : QAbstractListModel(parent)
    , pm_manager(nullptr)
    , pm_list(nullptr)
{
    pm_manager = manager;
    if(pm_manager == nullptr) {
        QMessageBox::critical(nullptr, "Error", "CardManager is null");
        return;
    }

    if(listIndex == userListIndex::UNDEFINED) {
        QMessageBox::critical(nullptr, "Error", "UserListIndex is undefined");
        return;
    }
    pm_list = &manager->getUserList(listIndex);
    if(pm_list == nullptr) {
        QMessageBox::critical(nullptr, "Error", "UserList is null");
        return;
    }
}

userListModel::~userListModel() {
    pm_manager = nullptr;
    pm_list = nullptr;
}

int userListModel::rowCount(const QModelIndex &parent) const {
    if(parent.isValid()) {
        return 0;
    }
    return pm_list->size();
}

QVariant userListModel::data(const QModelIndex &index, int role) const {
    if(!index.isValid() || index.row() >= pm_list->size()) {
        return QVariant();
    }

    if(role == Qt::DisplayRole) {
        const card_struct *card = &pm_list->at(index.row());
        return QString("%1-%2-%3-%4-%5")
            .arg(card->m_star)
            .arg(card->m_race)
            .arg(card->m_name)
            .arg(card->m_number)
            .arg(card->m_power)
            ;
    }

    return QVariant();
}

const card_struct& userListModel::getData(const QModelIndex &index) const {
    return pm_list->at(index.row());
}

void userListModel::appendData(const card_struct &card) {
    if(pm_list == nullptr) return;

    beginInsertRows(QModelIndex(), pm_list->size(), pm_list->size());
    pm_list->append(card);
    endInsertRows();
}

void userListModel::removeData(const QModelIndex &index) {
    if(pm_list == nullptr) return;

    beginRemoveRows(QModelIndex(), index.row(), index.row());
    pm_list->removeAt(index.row());
    endRemoveRows();
}

void userListModel::clear() {
    if(pm_list == nullptr) return;

    beginResetModel();
    pm_list->clear();
    endResetModel();
}

void userListModel::copyFrom(const QList<card_struct>& list) {
    beginResetModel();
    *pm_list = list;
    endResetModel();
}

int userListModel::contains(const card_struct &card) const {
    return pm_list->contains(card);
}
