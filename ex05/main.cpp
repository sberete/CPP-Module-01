#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string str;

    std::cout << "Please enter a complaint level (DEBUG, INFO, WARNING, ERROR):" << std::endl;
    if (!std::getline(std::cin, str)) 
    {
        std::cout << "End of file detected. Program terminated." << std::endl;
        return 0;
    }
    harl.complain(str);
}