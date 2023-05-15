#include <iostream>
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(const string &_name, const Point &_location) : Character(_name, _location, 110), _bulletsAmount(6) {}

    void Cowboy::shoot(Character *enemy)
    {
        if(this == enemy)
            throw runtime_error("Cant kill himself\n");
        if (!isAlive())
            throw runtime_error("cant shoot\n");
        if (!enemy->isAlive())
            throw runtime_error("This enemy is allready dead\n");
        else if (_bulletsAmount <= 0)
        {
            cout << "Out of bullets\n"
                 << endl;
            return;
        }
        else
        {
            enemy->hit(10);
            _bulletsAmount -= 1;
        }
    }

    bool Cowboy::hasboolets() const
    {
        return (_bulletsAmount > 0);
    }

    void Cowboy::reload()
    {
        if (!isAlive())
            throw runtime_error("can't reload\n");
        _bulletsAmount = 6;
    }

    string Cowboy::print() const
    {
        int _x = getLocation().getPointX();
        int _y = getLocation().getPointY();
        string output = "\tC(" + getName() + ")\n\n";
        if (isAlive())
        {
            output += "\t\tHit points: " + to_string(getHit()) + " Points left: " + to_string(getHealth()) + "Location: (" + to_string(_x) + "," + to_string(_y) + ")" + "\n\n";
        }
        else
        {
            output += "\t\tHit points: " + to_string(getHit()) + " Points left: -- " + "Location: (" + to_string(_x) + "," + to_string(_y) + ")" + "\n\n";
        }

        cout << output; // Print to the console

        return output;
    }

    void Cowboy::_attack(Character *enemy)
    {
        if(!enemy->isAlive() || !isAlive())
            return;
        if (!hasboolets())
            reload();
        else
            shoot(enemy);
    }

    int Cowboy::getBulletsAmount() const
    {
        return _bulletsAmount;
    }

} // namespace ariel
