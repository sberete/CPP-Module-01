#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* Zombiee = new Zombie(name);
    return Zombiee;
}