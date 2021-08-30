/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:04 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:04 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &cp)
{
	std::cout << "Brain copy called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = cp.ideas[i];
}


Brain::~Brain() 
{
	std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(unsigned int i) const
{
	return(this->ideas[i]);
}

void Brain::setIdea(unsigned int i, const std::string &idea)
{
	ideas[i] = idea;
}


Brain& Brain::operator=(const Brain& brain)
{
	std::cout << "Brain assignament operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
	return *this;
}