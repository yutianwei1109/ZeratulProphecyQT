#ifndef CARD_STRUCT_H
#define CARD_STRUCT_H

#include <iostream>
#include <string>
#include <unordered_set>

namespace cardRuleSets {
    extern const int minStar, maxStar;
    extern const std::unordered_set<std::string> cardRaces;
}

class card_struct
{
public:
    card_struct();
    card_struct(const int id, const int star,
                std::string&& race, std::string&& name,
                const int number, const int power);
    card_struct(const int id, const int star,
                const std::string& race, const std::string& name,
                const int number, const int power);
    card_struct(const std::string& format); // split by {'-', ','}
    static card_struct fromString(const std::string& format);

    bool operator==(const card_struct& that) const;

    operator std::string() const;
    std::string toString() const;

    int id() const;
    int star() const;
    const std::string& race() const;
    const std::string& name() const;
    int number() const;
    int power() const;

    void setStar(const int star);
    void setRace(const std::string& race);
    void setName(const std::string& name);
    void setNumber(const int number);
    void setPower(const int power);

private:
    int m_id{-1}; // < 0 undefined | 0 - custom card | > 0 - card from db
    int m_star{-1};
    std::string m_race{"<undefined>"};
    std::string m_name{"<undefined>"};
    int m_number{-1};
    int m_power{-1};
};

#endif // CARD_STRUCT_H
