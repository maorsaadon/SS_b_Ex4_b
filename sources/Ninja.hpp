#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
    private:
        int _speed;
        bool _inTeam = false;

    public:
        Ninja(const string &_name, const Point &_location, int _health, int _speed);

        // Ninja(const string &_name, const Point &_location);

        // Ninja(const Ninja &other);

        // Ninja(Ninja &&other) noexcept;

        // Ninja &operator=(const Ninja &other);

        // Ninja &operator=(Ninja &&other) noexcept;

        virtual ~Ninja(){}

        void move(Character *enemy);

        void slash(Character *enemy);

        string print() const override;

        void _attack(Character *enemy) override;

        int getSpeed() const;
    };

}

#endif