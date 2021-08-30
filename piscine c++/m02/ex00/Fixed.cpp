/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:17:55 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/30 14:17:55 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->rawBits);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed & Fixed::operator=(const Fixed & toassign)
{
	std::cout << "Assignation operator called" << std::endl;
	rawBits = toassign.getRawBits();
	return(*this);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}