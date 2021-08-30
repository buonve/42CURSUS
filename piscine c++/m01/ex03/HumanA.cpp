#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon):
weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}