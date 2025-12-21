#include "replace.hpp"

static char* new_name(const char* argv)
{
    size_t len = std::strlen(argv);
    char* name = new char[len + 9];
    std::strcpy(name, argv);
    std::strcat(name, ".replace");
    return name;
}


Lethimcook::Lethimcook(char **argv)
{
    _ifs.open(argv[1]);
    if (!_ifs){std::cerr << "Infile open failure" << std::endl; exit(1);}
    _name = new_name(argv[1]);
    _ofs.open(_name);
    if (!_ofs){std::cerr << "Outfile open failure" << std::endl; exit(1);}
    _to_find = argv[2];
    _to_replace = argv[3];
    _line = "";
}
Lethimcook::~Lethimcook()
{
    delete [] _name;
}
std::string Lethimcook::to_replace(const std::string& line)
{
    if (_to_find.empty())
        return line;
    std::string result = line;

    for (std::string::size_type pos = 0; (pos = result.find(_to_find, pos)) != std::string::npos; pos += _to_replace.length())
    {
        result.erase(pos, _to_find.length());
        result.insert(pos, _to_replace);
    }
    return result;
}


void Lethimcook::Tosee()
{
    for (;_ifs;)
    {
        std::getline(_ifs, _line);
        if (!_ifs)
            break ;
        _line = to_replace(_line);
        _ofs << _line << std::endl;
    }
}