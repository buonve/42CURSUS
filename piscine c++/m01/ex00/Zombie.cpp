#include "Zombie.hpp"

Zombie::Zombie(std::string nome)
{
	this->name = nome;
}

void Zombie::announce()
{
	std::cout << this->name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "[DEBUG] --- Zombie [";
	std::cout << this->name;
	std::cout << "] was destroyed." << std::endl;
}