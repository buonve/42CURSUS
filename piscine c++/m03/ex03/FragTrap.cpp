/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:08:41 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:08:41 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap constructor activated" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->setAttackDamage(30);
	this->setEnergyPoint(100);
	this->setHitPoint(100);
	std::cout << "FragTrap [" << this->getName() << "] is preparing to start ClapTrap HUNGER GAMES" << std::endl;
}

FragTrap::FragTrap(const FragTrap &op)
{
	*this = op;
}

FragTrap FragTrap::operator=(const FragTrap & op)
{
	this->setAttackDamage(op.getAttackDamage());
	this->setEnergyPoint(op.getEnergyPoint());
	this->setHitPoint(op.getHitPoint());
	this->setName(op.getName());
	std::cout << "FragTrap Copy constructor called, welcome [" << this->getName() << "]" << std::endl; 
	return(*this);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FRAGTRAP [" << this->getName() << "] IS ASKING OTHERS FOR AN HIGHFIVE!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Fragtrap [" << this->getName() << "] wanished in acid" << std::endl;
}
