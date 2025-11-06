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
    , m_allCards(QList<card_struct>{})
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
    QFile fp(":/data/core.csv");
    if(fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File core.csv open failed:" << fp.errorString();
        return;
    }

    QTextStream in(&fp);
    QString title = in.readLine();
    if(title.isEmpty()) {
        qDebug() << "Empty file or missing title.";
        fp.close();
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

        m_allCards.append(card);

        lineNum++;
    }
}
