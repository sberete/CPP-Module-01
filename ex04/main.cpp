#include <iostream>
#include <fstream>
#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        Lethimcook rep(argv);
        rep.Tosee();
    }
    else
        std::cerr << "Wrong numbers of arguments" << std::endl;
}