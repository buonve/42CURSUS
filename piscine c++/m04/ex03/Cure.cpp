/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:31 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:31 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& cure) : AMateria(cure.getType()) {}

Cure& Cure::operator= (const Cure& cure)
{
	this->materiaType = cure.getType();
	return (*this);
}

Cure* Cure::clone() const
{
	Cure *cure = new Cure(*this);
	return (cure);
}

Cure::~Cure() {}

void Cure::use(ICharacter& target)
{
	std::cout << "Healing " + target.getName() << std::endl;
}