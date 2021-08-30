#include "Karen.hpp"

Karen::Karen()
{
	this->f[0] = &Karen::debug;
	this->f[1] = &Karen::info;
	this->f[2] = &Karen::warning;
	this->f[3] = &Karen ::error;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}

Karen::~Karen(){}

void Karen::debug()
{
	std::cout << "[DEBUG] -- I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info()
{
	std::cout << "[INFO] -- I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning()
{
	std::cout << "[WARNING] -- I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error()
{
	std::cout << "[ERROR] -- This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain( std::string level )
{
	int i = 0;
	while(i < 4)
	{
		if(!level.compare(levels[i]))
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		(this->*f[i])();
		i++;
	case 1:
		(this->*f[i])();
		i++;
	case 2:
		(this->*f[i])();
		i++;
	case 3:
		(this->*f[i])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}