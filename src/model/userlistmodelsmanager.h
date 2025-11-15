#ifndef USERLISTMODELSMANAGER_H
#define USERLISTMODELSMANAGER_H

#include <QObject>
#include <QList>

#include "../common/card_struct.h"
#include "userlistmodel.h"

class UserListModelsManager : public QObject
{
    Q_OBJECT

public:
    // getInstance
    static UserListModelsManager* getInstance();
    // destroyInstance
    static void destroyInstance();
    // delete copy constructor and assignment operator
    UserListModelsManager(const UserListModelsManager &) = delete;
    UserListModelsManager &operator=(const UserListModelsManager &) = delete;
    // public methods
private:
    // private constructor
    explicit UserListModelsManager(QObject *parent = nullptr);
    // private destructor
    ~UserListModelsManager();
    // model init
    void initModels();
    void initFiles();
    bool checkAndCopyFile(const QString& targetFile, const QString& sourceFile);
    void loadFile(const QString& filePath, QList<card_struct>& list);
    // private instance
    static UserListModelsManager* m_instance;
    // private variables
    QList<card_struct> m_coreCards;
    QList<card_struct> m_dlcCards;
    UserListModel *m_featureListModel;
    UserListModel *m_noFeatureListModel;
    UserListModel *m_exceptListModel;
    UserListModel *m_possibleListModel;
};

#endif // USERLISTMODELSMANAGER_H
