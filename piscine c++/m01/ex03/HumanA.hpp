#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	public:
		void attack();
		HumanA(const std::string name, Weapon &weapon);
		~HumanA();
	private:
		Weapon &weapon;
		std::string name;
};

#endif