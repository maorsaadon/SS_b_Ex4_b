
#include "Team.hpp"

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

        if (!player->getInTeam() && player->isAlive() && _team.size() < 11)
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
            throw std::invalid_argument("enemy is nullptr");

        if (stillAlive() == 0 || enemy->stillAlive() == 0)
            throw runtime_error("Game over");

        if (!_teamLeader->isAlive())
            chooseNewLeader();

        while (stillAlive() > 0 && enemy->stillAlive() > 0)
        {
            Character *victim = findClosestLivingMember(enemy->_team, _teamLeader->getLocation());

            if (victim == nullptr)
            {
                break;
            }

            for (auto fighter : _team)
            {
                fighter->_attack(victim);
            }
        }

        if (stillAlive() <= 0 || enemy->stillAlive() <= 0)
        {
            cout << "Game over" << endl;
        }
    }

    int Team::stillAlive() const
    {
        int counter = 0;

        for (auto fighter : this->_team)
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
