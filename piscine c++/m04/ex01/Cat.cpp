/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:09 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:09 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	Cat::type = "Cat";
	cat_brain = new Brain;
}

Cat::~Cat() {
	delete cat_brain;
}

Cat::Cat(const Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	cat_brain = new Brain;
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) 
{
	std::cout << "Dog assignament operator called" << std::endl;
	type = cat.getType();
	*cat_brain = *cat.cat_brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat: \"Meeeeeeeeoww!\"" << std::endl;
}

void Cat::setIdea(unsigned int i, const std::string &idea)
{
	cat_brain->setIdea(i, idea);
}

std::string Cat::getIdea(unsigned int i) const
{
	return(cat_brain->getIdea(i));
}