#ifndef ZOMBIE_HPP
    #define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void _announce(void);
        void setName(int i, std::string name);

    private:
        std::string _name;
        int _nZombie;
        int _flag;
        int _o_flag;
};

Zombie* zombieHorde( int N, std::string name );

#endif
