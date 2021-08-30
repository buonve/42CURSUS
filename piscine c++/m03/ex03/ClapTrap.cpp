/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:08:31 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:08:32 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &nick)
{
	std::cout << "Welcome ClapTrap [" << nick << "]. You've been selected for this edition of the Hunger Games" << std::endl; 
	this->Hitpoints = 10;
	this->Energypoints = 10;
	this->AttackDamage = 0;
	this->Name = nick;
}

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap standard constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Humger Games ended. ClapTrap [" << this->Name << "] lost his/her utility." << std::endl;
}

ClapTrap ClapTrap::operator = (const ClapTrap &op)
{
	this->Name = op.Name;
	this->Hitpoints = op.Hitpoints;
	this->AttackDamage = op.AttackDamage;
	return(*this);
}

void ClapTrap::attack(std::string const & target)
{
	if(Hitpoints <= 0)
	{
		std::cout << "No hitpoints left. Cannot attack ClapTrap [" << target << "]." << std::endl;
		return ;
	}
	this->Hitpoints -= 1;
	std::cout << "ClapTrap [" << this->Name << "] attaks [" << target << "] causing " << this->AttackDamage << " damage. Remaining hitpoints: " << this->Hitpoints << std::endl;
}

bool ClapTrap::isDead()
{
	if(Energypoints == 0)
		return(true);
	return(false);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->Energypoints <= 0)
	{
		std::cout << "ClapTrap [" << this->Name << "] is already dead." << std::endl;
		return ;
	}
	else if(amount >= this->Energypoints)
	{
		std::cout << "ClapTrap [" << this->Name << "] get attaked with " << amount << " attack point, losing " << Energypoints << " energy points. No energy points left." << std::endl;
		std::cout << "ClapTrap [" << this->Name << "] died." << std::endl;
		this->Energypoints = 0;
		return ;
	}
	else
	{
		this->Energypoints -= amount;
		std::cout << "ClapTrap [" << this->Name << "] get attaked losing " << amount << " energy point.  Energypoints remaining: " << Energypoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(amount <= 0)
		std::cout << "Claptrap [" << this->Name << "]'s EnergyPoints cannot be reparied of " << amount <<  " energy points!" << std::endl;
	else
	{
		Energypoints += amount;
		std::cout << "Claptrap [" << this->Name << "]'s EnergyPoints increased of " << amount <<  " energy points!" << std::endl;
	}
}

std::string ClapTrap::getName() const
{
	return(this->Name);
}

void ClapTrap::setName(const std::string name)
{
	this->Name = name;
}

void ClapTrap::setHitPoint(unsigned int amount)
{
	this->Hitpoints = amount;
}

void ClapTrap::setEnergyPoint(unsigned int amount)
{
	this->Energypoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->AttackDamage = amount;
}

unsigned int ClapTrap::getHitPoint() const
{
	return(this->Hitpoints);
}
unsigned int ClapTrap::getEnergyPoint() const
{
	return(this->Energypoints);
}
unsigned int ClapTrap::getAttackDamage() const
{
	return(this->AttackDamage);
}