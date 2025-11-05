#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "card_struct.h"
#include "cardmanager.h"

class userListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit userListModel(QObject *parent = nullptr
        , CardManager *manager = nullptr
        , userListIndex listIndex = userListIndex::UNDEFINED);
    ~userListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    const card_struct& getData(const QModelIndex &index) const;

    void appendData(const card_struct &card);
    void removeData(const QModelIndex &index);

private:
    CardManager *pm_manager;
    QList<card_struct> *pm_list;
};

#endif // USERLISTMODEL_H
