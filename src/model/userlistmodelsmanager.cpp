#include "userlistmodelsmanager.h"

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>

// Singleton
UserListModelsManager* UserListModelsManager::m_instance = nullptr;

UserListModelsManager* UserListModelsManager::getInstance() {
    if (!m_instance) {
        QObject* parent = qApp->activeWindow() ? static_cast<QObject*>(qApp->activeWindow()) : qApp;
        m_instance = new UserListModelsManager(parent);
    }
    return m_instance;
}

void UserListModelsManager::destroyInstance() {
    if(m_instance) {
        delete m_instance;
        m_instance = nullptr;
    }
}
// private constructor
UserListModelsManager::UserListModelsManager(QObject *parent) 
    : QObject(parent)
    , m_coreCards(QList<card_struct>{})
    , m_dlcCards(QList<card_struct>{})
{
    if(!parent) {
        setParent(qApp);
    }
    
    initModels();
    initFiles();
    const QString& dataDir = QApplication::applicationDirPath() + "/Resources/cardData";
    loadFile(dataDir + "/core.csv", m_coreCards);
    loadFile(dataDir + "/dlc.csv", m_dlcCards);
}
// private destructor
UserListModelsManager::~UserListModelsManager() {
    delete m_featureListModel;
    delete m_noFeatureListModel;
    delete m_exceptListModel;
    delete m_possibleListModel;
}

// model init
void UserListModelsManager::initModels() {
    // init models
    m_featureListModel = new UserListModel(this);
    m_noFeatureListModel = new UserListModel(this);
    m_exceptListModel = new UserListModel(this);
    m_possibleListModel = new UserListModel(this);
}

void UserListModelsManager::initFiles() {
    const QString& dataDir = QApplication::applicationDirPath() + "/Resources/cardData";
    const QString& coreFile = dataDir + "/core.csv";
    const QString& dlcFile = dataDir + "/dlc.csv";
    if(!checkAndCopyFile(coreFile, ":/cardData/core.csv")) {
        return;
    }
    if(!checkAndCopyFile(dlcFile, ":/cardData/dlc.csv")) {
        return;
    }
}

bool UserListModelsManager::checkAndCopyFile(const QString& targetFile, const QString& sourceFile) {
    if(!(QFileInfo::exists(targetFile) && QFileInfo(targetFile).isFile())) {
        if(!QFileInfo::exists(sourceFile)) {
            qDebug() << "File " << sourceFile << " not exists.";
            return false;
        }

        QDir dir;
        if(
            !dir.exists(QFileInfo(targetFile).absolutePath()) &&
            !dir.mkdir(QFileInfo(targetFile).absolutePath())
        ) {
            qDebug() << "Create dir failed";
            return false;
        }

        if(QFileInfo::exists(targetFile) && !QFile::remove(targetFile)) {
            qDebug() << "Remove existing file failed";
            return false;
        }

        if(!QFile::copy(sourceFile, targetFile)) {
            qDebug() << "Copy file failed";
            return false;
        }

        qDebug() << "Copy file success";
    }
}

void UserListModelsManager::loadFile(const QString& filePath, QList<card_struct>& list) {
    QFile fp(filePath);
    if(fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File open failed:" << fp.errorString();
        return;
    }

    QTextStream in(&fp);
    QString title = in.readLine().trimmed();
    if(title.isEmpty()) {
        qDebug() << "Empty file or missing title.";
        fp.close();
        return;
    }

    int lineNum = 0;
    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) {
            qDebug() << "Empty line:" << lineNum;
            lineNum++;
            continue;
        }

        card_struct card{line.toStdString()};
        if(card == card_struct()) {
            qDebug() << "Invalid line:" << lineNum;
            lineNum++;
            continue;
        }

        list.append(card);
        lineNum++;
    }

    fp.close();
}
