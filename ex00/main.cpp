#include "Zombie.hpp"

int main()
{
    Zombie* newzombie = newZombie("Zombie 1");
    if (!newzombie)
        std::cerr << "Allocation of Zombie failled" << std::endl;
    
    newzombie->announce();
    
    randomChump("Zombie 2");
    
    delete newzombie;
}