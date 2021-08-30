/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:17 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:17 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog () : Animal()
{
	type = "Dog";
}

Dog::~Dog() {}

Dog::Dog(const Dog &cp)
{
	this->type = cp.type;
}

Dog &Dog::operator=(const Dog cp)
{
	this->type = cp.type;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog: \"Woooof Woof!\"" << std::endl;
}