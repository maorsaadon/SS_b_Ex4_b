#include <iostream>
#include <string>
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    Ninja::Ninja(const string &_name, const Point &_location, int _health, int _speed) : Character(_name, _location, _health), _speed(_speed) {}

    void Ninja::move(Character *enemy)
    {
        if (!isAlive())
            throw runtime_error("Im dead can't move\n");
        if (!enemy->isAlive())
            throw runtime_error("This enemy is allready dead\n");
        else
            setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), _speed));
    }

    void Ninja::slash(Character *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("Nullptr\n");
        if (this == enemy)
            throw runtime_error("Cant kill himself\n");
        if (!isAlive())
            throw runtime_error("Im dead can't kill enyone\n");
        if (!enemy->isAlive())
            throw runtime_error("This enemy is allready dead\n");
        else
        {
            if (getLocation().distance(enemy->getLocation()) < 1)
                enemy->hit(40);
            else
            {
                cout << "Too far to slash the enemy\n"
                     << endl;
                return;
            }
        }
    }

    string Ninja::print() const
    {
        string output = "N(" + getName() + ")\n\n";
        if (isAlive())
        {
            output += "\tis alive: " + to_string(isAlive()) + " Hit points: " + to_string(getHit()) + " Points left: " + to_string(getHealth()) + " Location: " + getLocation().print() + "\n\n";
        }
        else
        {
            output += "\tis alive: " + to_string(isAlive()) + " Hit points: " + to_string(getHit()) + " Points left: --" + " Location: " + getLocation().print() + "\n\n";
        }

        cout << output; // Print to the console

        return output;
    }

    void Ninja::attack(Character *enemy)
    {
        if (enemy == nullptr || !enemy->isAlive() || !isAlive())
            throw invalid_argument("attack failed");
        if (getLocation().distance(enemy->getLocation()) > 1)
            move(enemy);
        else
            slash(enemy);
    }

    int Ninja::getSpeed() const
    {
        return _speed;
    }

} // namespace ariel
