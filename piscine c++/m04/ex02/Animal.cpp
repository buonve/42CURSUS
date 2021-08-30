/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:10:59 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:10:59 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(std::string &type)
{
	this->type = type;
}

Animal::~Animal() {}

std::string Animal::getType() const
{
	return(type);
}

void Animal::makeSound() const
{
	std::cout << "No living creature here." << std::endl;
}

Animal::Animal(const Animal& pet)
{
	std::cout << "Copying" << std::endl;
	type = pet.type;
}

void	Animal::operator=(const Animal& op)
{
	std::cout << "Assigning" << std::endl;
	type = op.type;
}