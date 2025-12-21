#include "Zombie.hpp"

Zombie::Zombie(){_nZombie = 0;}

Zombie::~Zombie()
{
    std::cout << "Zombie n°" << _nZombie << " " << _name << " is destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << "Zombie n°" << _nZombie << " " << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(int nZombie, std::string name)
{
    _nZombie = nZombie + 1;
    _name = name;
}