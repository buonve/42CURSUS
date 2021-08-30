/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:36 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:36 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& ice) : AMateria(ice.getType()) {}

Ice& Ice::operator= (const Ice& ice)
{
	this->materiaType = ice.getType();
	return (*this);
}

Ice* Ice::clone() const
{
	Ice *ice = new Ice(*this);
	return (ice);
}

Ice::~Ice() {}

void Ice::use(ICharacter& target)
{
	std::cout << "Blasting an Ice attack to " + target.getName() << std::endl;
}