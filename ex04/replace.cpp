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
    _inputFilename = inputFilename;
    _outputFilename = new_name(inputFilename);
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
    std::ifstream ifs;
    ifs.open(_inputFilename); if (!ifs){std::cerr << "Infile open failure" << std::endl; exit(1);}
    std::ofstream ofs;
    ofs.open(_outputFilename); if (!ofs){std::cerr << "Outfile open failure" << std::endl; exit(1);}

    for (;;)
    {
        std::getline(ifs, line);
        if (!ifs)
            break ;
        line = to_replace(line);
        ofs << line << std::endl;
    }
}