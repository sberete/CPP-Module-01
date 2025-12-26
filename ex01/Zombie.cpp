#include "Zombie.hpp"

Zombie::Zombie(): _nZombie(0), _flag(0), _o_flag(0){}

Zombie::~Zombie()
{
    if (_flag)
        std::cout << "Zombie n°" << _nZombie << " " << _name << " is destroyed" << std::endl;
    if (_o_flag)
        std::cout << _name << " is destroyed" << std::endl;
}

void Zombie::announce()
{
    _o_flag = 1;
    std::cout  << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::_announce()
{
    _flag = 1;
    std::cout << "Zombie n°" << _nZombie << " " << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(int nZombie, std::string name)
{
    _nZombie = nZombie + 1;
    _name = name;
}