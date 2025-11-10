#include "userlistmodelsmanager.h"

#include <QApplication>
#include <QWidget>
#include <QDebug>

// Singleton
UserListModelsManager* m_instance = nullptr;

UserListModelsManager* UserListModelsManager::getInstance() {
    if (!m_instance) {
        QObject* parent = qApp->activeWindow() ? static_cast<QObject*>(qApp->activeWindow()) : qApp;
        m_instance = new UserListModelsManager(parent);
    }
    return m_instance;
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
}

// model init
void UserListModelsManager::initModels() {
    // init models
    m_featureListModel = new UserListModel(this);
    m_noFeatureListModel = new UserListModel(this);
    m_exceptListModel = new UserListModel(this);
    m_possibleListModel = new UserListModel(this);
    // load data
    QFile fp_core_csv(QApplication::applicationDirPath() + "/data/core.csv");
    if(fp_core_csv.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File core.csv open failed:" << fp_core_csv.errorString();
        return;
    }
    QFlie fp_dlc_csv(QApplication::applicationDirPath() + "/data/dlc.csv");
    if(fp_dlc_csv.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File dlc.csv open failed:" << fp_dlc_csv.errorString();
        fp_core_csv.close();
        return;
    }

    QTextStream in(&fp_core_csv);
    QString title = in.readLine();
    if(title.isEmpty()) {
        qDebug() << "Empty file or missing title.";
        fp_core_csv.close();
        return;
    }

    int lineNum = 0;
    while(!in.atEnd()) {
        QString line = in.readLine();
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

        m_coreCards.append(card);

        lineNum++;
    }
}
