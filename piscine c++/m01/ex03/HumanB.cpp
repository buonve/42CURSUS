#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
{
	this->weapon = 0;
	this->name = name;
}

HumanB::~HumanB(){}

void HumanB::setWeapon( Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with his " << weapon->getType() << std::endl;
}