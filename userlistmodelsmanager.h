#ifndef USERLISTMODELSMANAGER_H
#define USERLISTMODELSMANAGER_H

#include <QObject>
#include <QList>

#include "card_struct.h"
#include "userlistmodel.h"

class UserListModelsManager : public QObject
{
    Q_OBJECT

public:
    ~UserListModelsManager();

    // getInstance
    static UserListModelsManager* getInstance();
    // delete copy constructor and assignment operator
    UserListModelsManager(const UserListModelsManager &) = delete;
    UserListModelsManager &operator=(const UserListModelsManager &) = delete;
    // public methods
private:
    // private constructor
    explicit UserListModelsManager(QObject *parent = nullptr);
    // model init
    void initModels();
    // private instance
    static UserListModelsManager* m_instance;
    // private variables
    QList<card_struct> m_allCards;
    UserListModel *m_featureListModel;
    UserListModel *m_noFeatureListModel;
    UserListModel *m_exceptListModel;
    UserListModel *m_possibleListModel;
};

#endif // USERLISTMODELSMANAGER_H
