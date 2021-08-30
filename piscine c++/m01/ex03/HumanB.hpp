#ifndef HUMANAB_HPP
#define HUMANAB_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		void attack();
		void setWeapon(Weapon &weapon);
		HumanB(const std::string name);
		~HumanB();
	private:
		Weapon *weapon;
		std::string name;
};

#endif