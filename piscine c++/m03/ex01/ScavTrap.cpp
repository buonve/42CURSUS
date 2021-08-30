/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:59:20 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:04:51 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {}

ScavTrap::ScavTrap(std::string name):
ClapTrap(name)
{
	this->gatekeeper = false;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
	std::cout << "Scavtrap [" << this->getName() << "] built." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap [" << getName() << "] is useless and has been destroyed (ahah.)." << std::endl;
}

ScavTrap ScavTrap::operator = (const ScavTrap &op)
{
	this->setEnergyPoint(op.getEnergyPoint());
	this->setAttackDamage((op.getAttackDamage()));
	this->setName(op.getName());
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &cop): ClapTrap(cop)
{
	*this = cop;
}

void ScavTrap::guardGate()
{
	std::cout << "GateKeeper mode: ";
	if(gatekeeper == true)
	{
		gatekeeper = false;
		std::cout << "OFF" << std::endl;
	}
	else
	{
		gatekeeper = true;
		std::cout << "ON" << std::endl;
	}
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ATTACK FROM SCAVTRAP STARTED" << std::endl;
	if(getHitPoint() <= 0)
	{
		std::cout << "No hitpoints left. Cannot attack ScavTrap [" << target << "]." << std::endl;
		return ;
	}
	setHitPoint(getHitPoint() - 1);
	std::cout << "ScavTrap [" << getName() << "] attaks [" << target << "] causing " << getAttackDamage() << " damage. Remaining hitpoints: " << getHitPoint() << std::endl;
}