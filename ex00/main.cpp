#include "Zombie.hpp"

int main()
{
    Zombie* newzombie = newZombie("Test");
    if (!newZombie)
        std::cerr << "Allocation of Zombie failled" << std::endl, exit(1);
    randomChump("Test2");
    newzombie->announce();
    delete newzombie;
}