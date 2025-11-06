#include "card_struct.h"
#include <utility> // for std::move
#include <sstream>
#include <vector>
#include <stdexcept>

namespace ruleSets
{
    const std::unordered_set<int> cardStar = {0, 1, 2, 3, 4, 5, 6, 7};
    const std::unordered_set<std::string> cardRaces = {
        "Terran",  // 人族
        "Protoss", // 星灵
        "Zerg",    // 虫族
        "Neutral"  // 中立
    };
}

card_struct::card_struct() {}

card_struct::card_struct(const int id, const int star,
                         std::string &&race, std::string &&name,
                         const int number, const int power)
    : m_id(id), m_star(star), m_race(std::move(race)), m_name(std::move(name)), m_number(number), m_power(power)
{
}

card_struct::card_struct(const int id, const int star,
                         const std::string &race, const std::string &name,
                         const int number, const int power)
    : m_id(id), m_star(star), m_race(race), m_name(name), m_number(number), m_power(power)
{
}

card_struct::card_struct(const std::string &format)
    : card_struct(fromString(format))
{}

card_struct card_struct::fromString(const std::string &format)
{
    std::istringstream iss(format);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(iss, token, '-'))
    {
        tokens.push_back(token);
    }
    if (tokens.size() != 6)
    {
        throw std::runtime_error("Invalid card format");
    }
    return card_struct(
        std::stoi(tokens[0]),
        std::stoi(tokens[1]),
        tokens[2],
        tokens[3],
        std::stoi(tokens[4]),
        std::stoi(tokens[5]));
}

bool card_struct::operator==(const card_struct &that) const
{
    if (this->m_id == 0 && that.m_id == 0)
    {
        return this->m_star == that.m_star &&
               this->m_race == that.m_race &&
               this->m_name == that.m_name &&
               this->m_number == that.m_number &&
               this->m_power == that.m_power;
    }
    else if (this->m_id != 0 && that.m_id != 0)
        return this->m_id == that.m_id;
    else
        return false;
}

card_struct::operator std::string() const
{
    return toString();
}

std::string card_struct::toString() const
{
    std::ostringstream oss;
    oss << m_id << "-" << m_star << "-" << m_race << "-" << m_name << "-" << m_number << "-" << m_power;
    return oss.str();
}

int card_struct::id() const
{
    return m_id;
}
int card_struct::star() const
{
    return m_star;
}
const std::string &card_struct::race() const
{
    return m_race;
}
const std::string &card_struct::name() const
{
    return m_name;
}
int card_struct::number() const
{
    return m_number;
}
int card_struct::power() const
{
    return m_power;
}

void card_struct::setStar(const int star)
{
    if(m_id != 0) {
        throw std::runtime_error("Cannot set value when card is from database");
    }
    if(ruleSets::cardStar.find(star) == ruleSets::cardStar.end()) {
        throw std::runtime_error("Invalid star value");
    }
    m_star = star;
}
void card_struct::setRace(const std::string &race)
{
    if(m_id != 0) {
        throw std::runtime_error("Cannot set value when card is from database");
    }
    if(ruleSets::cardRaces.find(race) == ruleSets::cardRaces.end()) {
        throw std::runtime_error("Invalid race value");
    }
    m_race = race;
}
void card_struct::setName(const std::string &name)
{
    if(m_id != 0) {
        throw std::runtime_error("Cannot set value when card is from database");
    }
    m_name = name;
}
void card_struct::setNumber(const int number)
{
    if(m_id != 0) {
        throw std::runtime_error("Cannot set value when card is from database");
    }
    m_number = number;
}
void card_struct::setPower(const int power)
{
    if(m_id != 0) {
        throw std::runtime_error("Cannot set value when card is from database");
    }
    m_power = power;
}
