#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

using namespace std;

namespace ariel
{

    class Cowboy : public Character
    {

    private:
        int _bulletsAmount;

    public:
        Cowboy(const string &_name, const Point &_location);

        // Cowboy(const Cowboy &other);

        // Cowboy(Cowboy &&other) noexcept;

        // Cowboy &operator=(const Cowboy &other);

        // Cowboy &operator=(Cowboy &&other) noexcept;

        // ~Cowboy() = default;

        void shoot(Character *enemy);

        bool hasboolets() const;

        void reload();

        string print() const override;

        void _attack(Character *enemy) override;

        int getBulletsAmount() const;
    };
}

#endif