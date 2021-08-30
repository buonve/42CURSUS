/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:27 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:27 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(Character &character)
{
	*this = character;
}

Character & Character::operator=(Character &character)
{
	for(int i = 0; i < 4; i++)
	{
		if(character.inventory[i])
		{
			this->inventory[i] = character.inventory[i]->clone();
			delete character.inventory[i];
			character.inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		delete this->inventory[i];
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if(!this->inventory[i])
		{
			this->inventory[i] = m;
			std::cout << "Materia " + m->getType() + " equipped at index " << i << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Not valid index for inventory" << std::endl;
		return;
	}
	else if (!this->inventory[idx])
	{
		std::cout << "Inventory at " << idx << " index, already empty" << std::endl;
		return ;
	}
	std::cout << "Materia " + this->inventory[idx]->getType() + " unequipped from inventory at index " << idx << std::endl;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx])
	{
		inventory[idx]->use(target);
		delete inventory[idx];
		inventory[idx] = NULL;
	}
	else
		std::cout << "Inventory empty at index " << idx << std::endl;
}