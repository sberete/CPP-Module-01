#include "Harl.hpp"

enum Level
{
    NONE,
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

Level test (const std::string& level)
{
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return NONE;
}

void Harl::complain(std::string level)
{
    Level contain = test(level);
    
    switch (contain)
    {
        case DEBUG:
            debug();
            NL
            info();
            NL
            warning();
            NL
            error();
            break;
        case INFO:
            info();
            NL
            warning();
            NL
            error();
            break;

        case WARNING:
            warning();
            NL
            error();
            break;

        case ERROR:
            error();
            break;
            
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::warning()
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, where as you started working here just last month." << std::endl;

}

void Harl::error()
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;

}

