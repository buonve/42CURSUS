/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:13 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:13 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog () : Animal()
{
	std::cout << "Dog Constructor called" << std::endl;
	type = "Dog";
	dog_brain = new Brain;
}

Dog::~Dog() {
	delete dog_brain;
}

Dog::Dog(const Dog &dog)
{

	std::cout << "Dog copy constructor called" << std::endl;
	dog_brain = new Brain;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) 
{
	std::cout << "Dog assignament operator called" << std::endl;
	type = dog.getType();
	*dog_brain = *dog.dog_brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog: \"Woooof Woof!\"" << std::endl;
}

void Dog::setIdea(unsigned int i, const std::string &idea)
{
	dog_brain->setIdea(i, idea);
}

std::string Dog::getIdea(unsigned int i) const
{
	return(dog_brain->getIdea(i));
}