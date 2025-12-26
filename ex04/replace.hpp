#ifndef REPLACE_HPP
    #define REPLACE_HPP

#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>

class FileReplacer
{
    public:
        FileReplacer(char *inputFilename, char *stringToFind, char *stringToReplace);
        ~FileReplacer();
        void processFile();

    private:
        std::string _searchString;
        std::string _replaceString;
        const char *_outputFilename;
        const char *_inputFilename;
        std::string to_replace(const std::string& _line);
};

#endif

// Changer les nom des fonctions + class