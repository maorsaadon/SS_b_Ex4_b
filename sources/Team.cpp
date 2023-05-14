// #include "Team.hpp"

// namespace ariel
// {

//     Team::Team(Character *_teamLeader) : _teamLeader(_teamLeader)
//     {
//         _teamLeader->setInTeam(true);

//         // Check if the team leader is a cowboy
//         if (dynamic_cast<Cowboy *>(_teamLeader) != nullptr)
//         {
//             _team.push_back(_teamLeader); // Add the cowboy as the first element
//         }
//         else
//         {
//             _team.push_back(nullptr);     // Reserve the first element for a cowboy
//             _team.push_back(_teamLeader); // Add the non-cowboy leader
//         }
//     }
//     Team::Team(const Team &other) : _teamLeader(other._teamLeader), _team(other._team) {}

//     Team::Team(Team &&other) noexcept : _teamLeader(other._teamLeader), _team(other._team) {}

//     Team &Team::operator=(const Team &other)
//     {
//         if (this == &other)
//             return *this;

//         this->_teamLeader = other._teamLeader;
//         this->_team = other._team;
//         return *this;
//     }

//     Team &Team::operator=(Team &&other) noexcept
//     {
//         if (this == &other)
//             return *this;

//         this->_teamLeader = other._teamLeader;
//         this->_team = other._team;
//         return *this;
//     }

//     Team::~Team()
//     {
//         for (auto fighter : _team)
//         {
//             delete fighter;
//         }
//         _team.clear();
//     }

//     void Team::add(Character *player)
//     {
//         if (!player->getInTeam() || player->isAlive() || _team.size() < 11)
//         {
//             // Check if the player is a cowboy
//             if (dynamic_cast<Cowboy *>(player) != nullptr)
//                 _team.insert(_team.begin() + 1, player);// Add the cowboy at the beginning of the _team vector
//             else// Add the non-cowboy player at the end of the _team vector
//                 _team.push_back(player);

//             player->setInTeam(true);
//         }
//         else
//         {
//             throw invalid_argument("Can't add this player");
//         }
//     }

//     void Team::attack(Team *enemy)
//     {
//         if (!_teamLeader->isAlive())
//         {
//             chooseNewLeader();
//         }

//         Character *victim = nullptr;

//         while (stillAlive() > 0 && enemy->stillAlive() > 0)
//         {
//             victim = findClosestLivingMember(enemy->_team, _teamLeader->getLocation());

//             if (victim == nullptr)
//                 break;

//             for (auto fighter : _team)
//                 if (fighter->isAlive())
//                     fighter->_attack(victim);
//         }

//         if (stillAlive() == 0 || enemy->stillAlive() == 0)
//             cout << "Game over" << endl;
//     }

//     int Team::stillAlive() const
//     {
//         int counter = 0;
//         for (auto fighter : _team)
//             if (fighter->isAlive())
//                 counter++;
//         return counter;
//     }

//     void Team::print() const
//     {
//         cout << "The member team : \n"
//              << endl;
//         for (auto fighter : _team)
//             fighter->print();
//     }

//     Character *Team::getLeader() const
//     {
//         return _teamLeader;
//     }

//     vector<Character *> Team::getTeam() const
//     {
//         return _team;
//     }

//     void Team::chooseNewLeader()
//     {
//         Character *newLeader = nullptr;
//         double minDistance = numeric_limits<double>::max();

//         for (auto fighter : _team)
//         {
//             if (fighter->isAlive() && fighter != _teamLeader)
//             {
//                 double distance = _teamLeader->getLocation().distance(fighter->getLocation());
//                 if (distance < minDistance)
//                 {
//                     minDistance = distance;
//                     newLeader = fighter;
//                 }
//             }
//         }

//         if (newLeader != nullptr)
//             _teamLeader = newLeader;
//     }

//     Character *Team::findClosestLivingMember(const vector<Character *> &characters, const Point &targetLocation)
//     {
//         Character *closestCharacter = nullptr;
//         double minDistance = numeric_limits<double>::max();

//         for (auto character : characters)
//         {
//             if (character->isAlive())
//             {
//                 double distance = targetLocation.distance(character->getLocation());
//                 if (distance < minDistance)
//                 {
//                     minDistance = distance;
//                     closestCharacter = character;
//                 }
//             }
//         }

//         return closestCharacter;
//     }

// }

#include "Team.hpp"

#include <cmath>
#include <stdexcept>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>
#include <memory>

namespace ariel
{

    Team::Team(Character *_teamLeader) : _teamLeader(_teamLeader)
    {
        if (_teamLeader == nullptr)
            throw invalid_argument("Team leader cannot be null");

        this->add(_teamLeader);
    }

    Team::Team(const Team &other) : _teamLeader(other._teamLeader), _team(other._team) {}

    Team::Team(Team &&other) noexcept : _teamLeader(other._teamLeader), _team(other._team) {}

    Team &Team::operator=(const Team &other)
    {
        if (this == &other)
            return *this;

        this->_teamLeader = other._teamLeader;
        this->_team = other._team;
        return *this;
    }

    Team &Team::operator=(Team &&other) noexcept
    {
        if (this == &other)
            return *this;

        this->_teamLeader = other._teamLeader;
        this->_team = other._team;
        return *this;
    }

    Team::~Team()
    {
        for (auto fighter : _team)
        {
            delete fighter;
        }
        _team.clear();
    }

    void Team::add(Character *player)
    {

        if (!player->getInTeam() && player->isAlive() && getTeam().size() < 11)
        {
            if (dynamic_cast<Cowboy *>(player) != nullptr)
                _team.insert(_team.begin(), player);
            else
                _team.push_back(player);

            player->setInTeam(true);
        }
        else
            throw runtime_error("Can't add this player");
    }

    void Team::attack(Team *enemy)
    {

        if (enemy == nullptr)
            throw invalid_argument("nullptr");

        if (stillAlive() == 0 || enemy->stillAlive() == 0)
        {
            cout << "Game over" << endl;
            return;
        }

        if (!_teamLeader->isAlive())
        {
            chooseNewLeader();
        }

        Character *victim = nullptr;

        while (stillAlive() > 0 && enemy->stillAlive() > 0)
        {
            victim = findClosestLivingMember(enemy->_team, _teamLeader->getLocation());
            
            if (victim == nullptr)
                break;

            while (victim->isAlive())
            {
                for (auto fighter : _team)
                    if (fighter->isAlive() && victim->isAlive())
                        fighter->_attack(victim);
            }
        }

        if (stillAlive() == 0 || enemy->stillAlive() == 0)
            cout << "Game over" << endl;
    }

    int Team::stillAlive() const
    {
        int counter = 0;

        for (auto fighter : _team)
            if (fighter->isAlive())
                counter++;
        return counter;
    }

    void Team::print() const
    {
        cout << "The member team : \n"
             << endl;
        for (auto fighter : _team)
            fighter->print();
    }

    Character *Team::getLeader() const
    {
        return _teamLeader;
    }

    vector<Character *> Team::getTeam() const
    {
        return _team;
    }

    void Team::chooseNewLeader()
    {
        Character *newLeader = nullptr;
        double minDistance = numeric_limits<double>::max();

        for (auto fighter : _team)
        {
            if (fighter->isAlive() && fighter != _teamLeader)
            {
                double distance = _teamLeader->getLocation().distance(fighter->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    newLeader = fighter;
                }
            }
        }

        if (newLeader != nullptr)
            _teamLeader = newLeader;
    }

    Character *Team::findClosestLivingMember(const vector<Character *> &characters, const Point &targetLocation)
    {
        Character *closestCharacter = nullptr;
        double minDistance = numeric_limits<double>::max();

        for (auto character : characters)
        {
            if (character->isAlive())
            {
                double distance = targetLocation.distance(character->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestCharacter = character;
                }
            }
        }

        return closestCharacter;
    }

}
