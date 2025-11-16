#include "userlistmodelsmanager.h"

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QDateTime>

// Singleton
UserListModelsManager* UserListModelsManager::m_instance = nullptr;

UserListModelsManager* UserListModelsManager::getInstance() {
    if (!m_instance) {
        QObject* parent = qApp;
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
// public methods
UserListModel* UserListModelsManager::getUserListModel(UserListType type) {
    switch (type) {
        case UserListType::FEATURE:
            return m_featureListModel;
        case UserListType::NOFEATURE:
            return m_noFeatureListModel;
        case UserListType::EXCEPT:
            return m_exceptListModel;
        case UserListType::POSSIBLE:
            return m_possibleListModel;
        default:
            return nullptr;
    }
}
QStringList UserListModelsManager::getNameListWithStarAndRace(int star, QString raceQStr) {
    QStringList nameList;
    if (m_coreCards.empty()) return nameList;
    for (const auto& card : m_coreCards) {
        if (card.star() == star && QString::fromStdString(card.race()) == raceQStr) {
            nameList.append(QString::fromStdString(card.name()));
        }
    }
    if (m_dlcCards.empty()) return nameList;
    for (const auto& card : m_dlcCards) {
        if (card.star() == star && QString::fromStdString(card.race()) == raceQStr) {
            nameList.append(QString::fromStdString(card.name()));
        }
    }
    return nameList;
}
const card_struct UserListModelsManager::getCardByName(QString cardName) {
    if (cardName.isEmpty()) return card_struct();
    if (cardName == "<custom>") return card_struct(0, 1, "Neutral", "<custom>", 0, 0);
    for (const auto& card : m_coreCards) {
        if (QString::fromStdString(card.name()) == cardName) {
            return card;
        }
    }
    for (const auto& card : m_dlcCards) {
        if (QString::fromStdString(card.name()) == cardName) {
            return card;
        }
    }
    return card_struct();
}
int UserListModelsManager::getCardIdByCardName(QString cardName) {
    if (cardName.isEmpty()) return -1;
    if (cardName == "<custom>") return 0;
    for (const auto& card : m_coreCards) {
        if (QString::fromStdString(card.name()) == cardName) {
            return card.id();
        }
    }
    for (const auto& card : m_dlcCards) {
        if (QString::fromStdString(card.name()) == cardName) {
            return card.id();
        }
    }
    return -1;
}
void UserListModelsManager::updateUserList(UserListUpdateData data) {
    switch (data.type) {
        case UserListType::FEATURE:
            if (data.op == UserListOperation::APPEND) {
                m_featureListModel->appendCard(data.card);
            } else if (data.op == UserListOperation::REMOVE) {
                m_featureListModel->removeCard(data.card);
            }
            break;
        case UserListType::NOFEATURE:
            if (data.op == UserListOperation::APPEND) {
                m_noFeatureListModel->appendCard(data.card);
            } else if (data.op == UserListOperation::REMOVE) {
                m_noFeatureListModel->removeCard(data.card);
            }
            break;
        case UserListType::EXCEPT:
            if (data.op == UserListOperation::APPEND) {
                if(data.card.name() != "<custom>")
                    m_exceptListModel->appendCard(data.card);
            } else if (data.op == UserListOperation::REMOVE) {
                m_exceptListModel->removeCard(data.card);
            }
            break;
        case UserListType::POSSIBLE:
            if (data.op == UserListOperation::APPEND) {
                qDebug() << "possible list is not appendable";
                return;
            } else if (data.op == UserListOperation::REMOVE) {
                m_possibleListModel->removeCard(data.card);
            }
            break;
        default:
            break;
    }
    emit userListChanged(data);
}
void UserListModelsManager::refreshPossibleLists() {
    if(!m_isInit) return;
    m_possibleListModel->clear();
    m_possibleListModel->setCardList(m_coreCards);
    QList<card_struct> earseList;
    for(const auto& card: m_coreCards) {
        if(!isPossibleCard(card)) earseList.append(card);
    }
    for(const auto& card: earseList) {
        m_possibleListModel->removeCard(card);
    }
}
bool UserListModelsManager::isPossibleCard(const card_struct& card) {
    if(!m_isInit) return false;
    if(m_exceptListModel->contains(card)) return false;
    for(const auto& noFeatureCard: m_noFeatureListModel->getCardList()) {
        if(
            noFeatureCard.race() == card.race() ||
            noFeatureCard.number() == card.number() ||
            (noFeatureCard.power() > card.power() - 200 && noFeatureCard.power() < card.power() + 200)
        ) {
            return false;
        }
    }
    for(const auto& featureCard: m_featureListModel->getCardList()) {
        if(
            featureCard.race() != card.race() &&
            featureCard.number() != card.number() &&
            (featureCard.power() < card.power() - 200 || featureCard.power() > card.power() + 200)
        ) {
            return false;
        }
    }
    return true;
}
void UserListModelsManager::reset() {
    m_featureListModel->clear();
    m_noFeatureListModel->clear();
    m_exceptListModel->clear();
    m_possibleListModel->clear();
    m_possibleListModel->setCardList(m_coreCards);
}
// public slots
void UserListModelsManager::on_userListChanged(UserListUpdateData data) {
    QList<card_struct> earseList;
    switch (data.type) {
        case UserListType::FEATURE:
            if(data.op == UserListOperation::APPEND) {
                for(const auto& card: m_possibleListModel->getCardList()) {
                    if(
                        card.race() != data.card.race() &&
                        card.number() != data.card.number() &&
                        (card.power() < data.card.power() - 200 || card.power() > data.card.power() + 200)
                    ) {
                        earseList.append(card);
                    }
                }
            } else if (data.op == UserListOperation::REMOVE) {
                refreshPossibleLists();
            }
            break;
        case UserListType::NOFEATURE:
            if(data.op == UserListOperation::APPEND) {
                for(const auto& card: m_possibleListModel->getCardList()) {
                    if(
                        card.race() == data.card.race() || 
                        card.number() == data.card.number() ||
                        (card.power() > data.card.power() - 200 && card.power() < data.card.power() + 200)
                    ) {
                        earseList.append(card);
                    }
                }
            } else if (data.op == UserListOperation::REMOVE) {
                refreshPossibleLists();
            }
            break;
        case UserListType::EXCEPT:
            if(data.op == UserListOperation::APPEND) {
                earseList.append(data.card);
            } else if (data.op == UserListOperation::REMOVE) {
                if(isPossibleCard(data.card)) {
                    m_possibleListModel->appendCard(data.card);
                }
            }
            break;
        case UserListType::POSSIBLE:
            if(data.op == UserListOperation::REMOVE) {
                earseList.append(data.card);
                m_exceptListModel->appendCard(data.card);
            }
            break;
        default:
            break;
    }
    for(const auto& card: earseList) {
        m_possibleListModel->removeCard(card);
    }
}
// private constructor
UserListModelsManager::UserListModelsManager(QObject *parent) 
    : QObject(parent)
    , m_isInit(false)
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
    
    connect(
        this, &UserListModelsManager::userListChanged,      // signal
        this, &UserListModelsManager::on_userListChanged    // slot
    );

    m_isInit = true;
}
// private destructor
UserListModelsManager::~UserListModelsManager() {
    
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
    const QString& appDir = QApplication::applicationDirPath();
    const QString& resDir = appDir + "/Resources";
    if(!checkAndCreateDirectory(resDir)) {
        qDebug() << "Create resDir failed";
        return;
    }
    const QString& dataDir = resDir + "/cardData";
    if(!checkAndCreateDirectory(dataDir)) {
        qDebug() << "Create dataDir failed";
        return;
    }
    const QString& coreFile = dataDir + "/core.csv";
    const QString& dlcFile = dataDir + "/dlc.csv";
    if(!checkAndCopyFile(coreFile, ":/cardData/core.csv")) {
        return;
    }
    if(!checkAndCopyFile(dlcFile, ":/cardData/dlc.csv")) {
        return;
    }
}

bool UserListModelsManager::checkAndCreateDirectory(const QString& dirPath) {
    QDir dir(dirPath);
    if(!dir.exists()) {
        return dir.mkdir(dirPath);
    }
    return true;
}

bool UserListModelsManager::checkAndCopyFile(const QString& targetFile, const QString& sourceFile) {
    if(!(QFileInfo::exists(targetFile) && QFileInfo(targetFile).isFile())) {
        QFileInfo sourceFileInfo(sourceFile);
        if(sourceFileInfo.exists()) {
            //last modified time
            if(isGuiAvailable())
                QMessageBox::information(
                    nullptr, 
                    "Last modified date",
                    QString("File last modified date: %1").
                        arg(sourceFileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss")),
                    QMessageBox::Ok
                );
            else 
                qDebug() << "File last modified date: " << sourceFileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss");
        } else {
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

        if(!QFile::copy(sourceFile, targetFile)) {
            qDebug() << "Copy file failed";
            return false;
        }

        qDebug() << "Copy file success";
    } else {
        QFileInfo targetFileInfo(targetFile);
        if (targetFileInfo.exists()) {
            //last modified time
            if(isGuiAvailable())
                QMessageBox::information(
                    nullptr, 
                    "Last modified date",
                    QString("File last modified date: %1").
                        arg(targetFileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss")),
                    QMessageBox::Ok
                );
            else
                qDebug() << "File last modified date: " << targetFileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss");
        }
    }
    return true;
}

void UserListModelsManager::loadFile(const QString& filePath, QList<card_struct>& list) {
    QFile fp(filePath);
    if(!fp.open(QIODevice::ReadOnly | QIODevice::Text)) {
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

    qDebug() << "Load file success:" << filePath << "lineNum:" << lineNum--;
    fp.close();
}

bool UserListModelsManager::isGuiAvailable() {
    if(!qobject_cast<QApplication*>(QCoreApplication::instance())) {
        return false;
    }
    if(QGuiApplication::primaryScreen() == nullptr) {
        return false;
    }
    return true;
}
