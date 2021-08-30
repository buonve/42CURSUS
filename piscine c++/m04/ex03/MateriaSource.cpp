/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:48 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:48 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->learned[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource &source)
{
	*this = source;
}

MateriaSource & MateriaSource::operator=(MateriaSource &source)
{
	for (int i = 0; i < 4; i++) {
		if (learned[i])
			delete learned[i];
		learned[i] = source.learned[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* amateria)
{
	for(int i = 0; i < 4; i++)
	{
		if (!this->learned[i])
		{
			this->learned[i] = amateria->clone();
			std::cout << "Amateria " + amateria->getType() + " learned in index " << i << std::endl;
			return ;
		}
	}
	std::cout << "No free slots in learning capabilities" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i]->getType() == type) 
			return (learned[i]->clone());
	}
	std::cout << " Materia " + type + " not available" << std::endl;
	return (0);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (learned[i])
			delete learned[i];
}
