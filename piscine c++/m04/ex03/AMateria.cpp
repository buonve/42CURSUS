/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:23 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:23 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->materiaType = type;
}

AMateria::AMateria(AMateria const & materia)
{
	*this = materia;
}

AMateria::~AMateria() {}

AMateria & AMateria::operator= (const AMateria& amateria)
{
	this->materiaType = amateria.getType();
	return(*this);
}

std::string const & AMateria::getType() const
{
	return(this->materiaType);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "You're never seeing this message" << std::endl;
}