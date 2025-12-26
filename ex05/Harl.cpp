#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::map<std::string, void (Harl::*)(void)> m;

    m["DEBUG"] = &Harl::debug;
    m["INFO"] = &Harl::info;
    m["WARNING"] = &Harl::warning;
    m["ERROR"] = &Harl::error;

    try
    {
        (this->*m.at(level))();
    }
    catch(const std::exception&)
    {
        std::cout << "Unknown complaint level" << std::endl;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, where as you started working here just last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

