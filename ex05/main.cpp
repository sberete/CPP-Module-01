#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string str;

    std::cout << "Put :" << std::endl;
    std::getline(std::cin, str);
    harl.complain(str);
}