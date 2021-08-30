/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:12 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:12 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal()
{
	Cat::type = "Cat";
}

Cat::~Cat() {}

Cat::Cat(const Cat &cp)
{
	this->type = cp.type;
}

Cat &Cat::operator=(const Cat &cp)
{
	this->type = cp.type;
	return(*this);
}


void Cat::makeSound() const
{
	std::cout << "Cat: \"Meeeeeeeeoww!\"" << std::endl;
}