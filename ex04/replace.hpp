#ifndef REPLACE_HPP
    #define REPLACE_HPP

#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>

class Lethimcook
{
    public:
        Lethimcook(char **argv);
        ~Lethimcook();
        void Tosee();

    private:
        std::string _to_find;
        std::string _to_replace;
        const char *_name;
        std::string _line;
        std::ifstream _ifs;
        std::ofstream _ofs;
        std::string to_replace(const std::string& _line);

};

#endif