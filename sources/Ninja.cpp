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
        {
            cout << "This character is dead\n"
                 << endl;
            return;
        }
        else
            setLocation(Point::moveTowards(getLocation(), enemy->getLocation(), _speed));
    }

    void Ninja::slash(Character *enemy)
    {
       
        if(this == enemy)
            throw runtime_error("Cant kill himself\n");
        if (!isAlive())
            throw runtime_error("Im dead canwt kill enyone\n");
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
        string output = "\tN(" + getName() + ")\n\n";
        if (isAlive())
        {
            output += "\t\tHit points: " + to_string(getHit()) + " Points left: " + to_string(getHealth()) + "\n\n";
        }
        else
        {
            output += "\t\tHit points: " + to_string(getHit()) + " Points left: --\n\n";
        }

        cout << output; // Print to the console

        return output;
    }

    void Ninja::_attack(Character *enemy)
    {
        if (getLocation().distance(enemy->getLocation()) > 100)
            move(enemy);
        else
            slash(enemy);
    }

    int Ninja::getSpeed() const
    {
        return _speed;
    }

} // namespace ariel
