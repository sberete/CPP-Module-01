#include "replace.hpp"

static char* new_name(const char* argv)
{
    size_t len = std::strlen(argv);
    char* name = new char[len + 9];
    std::strcpy(name, argv);
    std::strcat(name, ".replace");
    return name;
}

FileReplacer::FileReplacer(char *inputFilename, char *stringToFind, char *stringToReplace)
{
    _ifs.open(inputFilename);
    if (!_ifs){std::cerr << "Infile open failure" << std::endl; exit(1);}
    _outputFilename = new_name(inputFilename);
    _ofs.open(_outputFilename);
    if (!_ofs){std::cerr << "Outfile open failure" << std::endl; exit(1);}
    _searchString = stringToFind;
    _replaceString = stringToReplace;
}

FileReplacer::~FileReplacer()
{
    delete [] _outputFilename;
}

std::string FileReplacer::to_replace(const std::string& line)
{
    if (_searchString.empty())
        return line;

    std::string result = line;

    for (std::string::size_type pos = 0; (pos = result.find(_searchString, pos)) != std::string::npos; pos += _replaceString.length())
    {
        result.erase(pos, _searchString.length());
        result.insert(pos, _replaceString);
    }
    return result;
}

void FileReplacer::processFile()
{
    std::string line;
    for (;_ifs;)
    {
        std::getline(_ifs, line);
        if (!_ifs)
            break ;
        line = to_replace(line);
        _ofs << line << std::endl;
    }
}