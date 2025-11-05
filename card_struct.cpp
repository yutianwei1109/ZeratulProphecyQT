#include "card_struct.h"
#include <utility> // for std::move

namespace ruleSets {
    QStringList cardRaces = {
        "Terran",   // 人族
        "Protoss",  // 星灵
        "Zerg",     // 虫族
        "Neutral"   // 中立
    };
}

card_struct::card_struct(const int id, const int star,
                         QString&& race, QString&& name,
                         const int number, const int power)
    :m_id(id)
    ,m_star(star)
    ,m_race(std::move(race))
    ,m_name(std::move(name))
    ,m_number(number)
    ,m_power(power)
{}

card_struct::card_struct(const int id, const int star,
                         const QString& race, const QString& name,
                         const int number, const int power)
    :m_id(id)
    ,m_star(star)
    ,m_race(race)
    ,m_name(name)
    ,m_number(number)
    ,m_power(power)
{}

bool card_struct::operator==(const card_struct& that) const {
    return m_id == that.m_id;
}
