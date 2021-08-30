/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:28 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:28 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongType!";
}

WrongAnimal::~WrongAnimal()
{}

WrongAnimal::WrongAnimal(const WrongAnimal &cp)
{
	this->type = cp.type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &cp)
{
	this->type = cp.type;
	return(*this);
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WRONG ANIMAL MAKES NO SOUND" << std::endl;
}