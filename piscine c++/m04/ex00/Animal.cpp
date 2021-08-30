/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:07 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:07 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(Animal &pet)
{
	*this = pet;
}

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

Animal &Animal::operator=(const Animal &an)
{
	this->type = an.type;
	return (*this);
}