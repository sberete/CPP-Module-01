
#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        FileReplacer replacer(argv[1], argv[2], argv[3]);
        replacer.processFile();
    }
    else
        std::cerr << "Wrong numbers of arguments" << std::endl;
}