/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:32 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:32 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat():
WrongAnimal()
{
	WrongCat::type = "Wrong Cat";
}

WrongCat::~WrongCat()
{}

WrongCat::WrongCat(const WrongCat &cp)
{
	this->type = cp.type;
}

WrongCat &WrongCat::operator=(const WrongCat &cp)
{
	this->type = cp.type;
	return(*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Dog? or Cat?" << std::endl;
}