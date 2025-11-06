#include "userlistmodel.h"

#include <QMessageBox>

userListModel::userListModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_cardList()
{

}

userListModel::~userListModel() {
    
}
