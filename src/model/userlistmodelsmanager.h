#ifndef USERLISTMODELSMANAGER_H
#define USERLISTMODELSMANAGER_H

#include <QObject>
#include <QList>

#include "../common/card_struct.h"
#include "userlistmodel.h"

enum class UserListType {
    UNDEFINED,
    FEATURE,
    NOFEATURE,
    EXCEPT,
    POSSIBLE
};

enum class UserListOperation {
    UNDEFINED,
    APPEND,
    REMOVE
};

struct UserListUpdateData {
    UserListType type{UserListType::UNDEFINED};
    UserListOperation op{UserListOperation::UNDEFINED};
    card_struct card;
};

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
    UserListModel* getUserListModel(UserListType type);
    QStringList getNameListWithStarAndRace(int star, QString raceQStr);
    void updateUserList(UserListUpdateData data);
    void refreshPossibleLists();
    bool isPossibleCard(const card_struct& card);
public slots:
    void on_userListChanged(UserListUpdateData data);
signals:
    void userListChanged(UserListUpdateData data);
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
    bool isGuiAvailable();
    // private instance
    static UserListModelsManager* m_instance;
    // private variables
    bool m_isInit;
    QList<card_struct> m_coreCards;
    QList<card_struct> m_dlcCards;
    UserListModel *m_featureListModel;
    UserListModel *m_noFeatureListModel;
    UserListModel *m_exceptListModel;
    UserListModel *m_possibleListModel;
};

#endif // USERLISTMODELSMANAGER_H
