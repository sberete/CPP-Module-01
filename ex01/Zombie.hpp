#ifndef ZOMBIE_HPP
    #define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;
        int _nZombie;

    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void setName(int i, std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
