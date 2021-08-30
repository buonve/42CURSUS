/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:42:23 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/28 22:32:59 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{	
	this->fixedPointValue = raw;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = num << this->binaryPoint;
}

Fixed::Fixed(const float flt)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = (int)(roundf(flt * (1 << this->binaryPoint)));
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat() const
{
	return ((float)this->fixedPointValue / (float)(1 << this->binaryPoint));
}

int		Fixed::toInt() const
{
	return ((int)this->fixedPointValue >> this->binaryPoint);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
    out << fixe.toFloat();
    return (out);
}

Fixed & Fixed::operator=(const Fixed & toassign)
{
	std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = toassign.getRawBits();
	return(*this);
}