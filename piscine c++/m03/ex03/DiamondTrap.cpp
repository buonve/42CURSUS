/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:08:36 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:08:36 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <string>

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap standard constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name):
ClapTrap(name + "_clap_name"),
FragTrap(name),
ScavTrap(name)
{
	std::string clap_name = name;
	this->set_protected_name(name);
	setHitPoint(FragTrap::getHitPoint());
	setEnergyPoint(ScavTrap::getEnergyPoint());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DIAMONDTRAP [" << this->Name << "] has been created yoyo wewe PEPPERE." << std::endl;
}

void DiamondTrap::set_protected_name(const std::string name)
{
	this->Name = name;
}

DiamondTrap DiamondTrap::operator = (const DiamondTrap &op) 
{
	this->Name = op.getName();
	ClapTrap::setName(op.ClapTrap::getName().append("_clap_name"));
	this->setHitPoint(op.FragTrap::getHitPoint());
	this->setAttackDamage(op.ScavTrap::getAttackDamage());
	this->setHitPoint(op.FragTrap::getHitPoint());
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cop) :
ClapTrap(cop),
FragTrap(cop),
ScavTrap(cop) 
{
	*this = cop;
}

void DiamondTrap::whoAmI()
{
	std::cout << "HELLOOOO!!!! My DiamondTrap name is: [" << this->Name << "]." << std::endl;
	std::cout << "Goodmorning Sir. My Claptrap name is: [" << this->ClapTrap::getName() << "]." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DIAMONDTRAP [" << this->Name << "]: \"My work is finished\"" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}