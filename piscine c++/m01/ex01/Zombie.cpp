#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << "[DEBUG] --- Zombie [";
	std::cout << this->name;
	std::cout << "] was destroyed." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
