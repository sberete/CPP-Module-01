#include "Zombie.hpp"

int main()
{
    int nZombies = 10;
    Zombie* Zombies = zombieHorde(nZombies, "foo");

    for(int i = 0; i < nZombies; i++)
        Zombies[i].announce();

    delete [] Zombies;
}