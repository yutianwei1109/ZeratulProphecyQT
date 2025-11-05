#ifndef CARD_STRUCT_H
#define CARD_STRUCT_H

#include <QString>
#include <QStringList>

namespace ruleSets {
    extern QStringList cardStar;
    extern QStringList cardRaces;
}

struct card_struct
{
    card_struct();
    card_struct(const int id, const int star,
                QString&& race, QString&& name,
                const int number, const int power);
    card_struct(const int id, const int star,
                const QString& race, const QString& name,
                const int number, const int power);

    bool operator==(const card_struct& that) const;
    QString toString() const;
    operator QString() const;

    int m_id;
    int m_star;
    QString m_race;
    QString m_name;
    int m_number;
    int m_power;
};

#endif // CARD_STRUCT_H
