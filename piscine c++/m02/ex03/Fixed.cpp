/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:42:23 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/29 18:53:14 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
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
	//std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = num << this->binaryPoint;
}

Fixed::Fixed(const float flt)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = (int)(roundf(flt * (1 << this->binaryPoint)));
}

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
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
	//std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = toassign.getRawBits();
	return(*this);
}

bool Fixed::operator > (const Fixed &toassign) const
{
	if(this->fixedPointValue > toassign.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator < (const Fixed &toassign) const
{
	if(this->fixedPointValue < toassign.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator >= (const Fixed &toassign) const
{
	if(this->fixedPointValue >= toassign.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator <= (const Fixed &toassign) const
{
	if(this->fixedPointValue <= toassign.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator == (const Fixed &toassign) const
{
	if(this->fixedPointValue == toassign.getRawBits())
		return(true);
	return(false);
}

bool Fixed::operator != (const Fixed &toassign) const
{
	if(this->fixedPointValue != toassign.getRawBits())
		return(true);
	return(false);
}

Fixed Fixed::operator + (const Fixed &toassign) const
{
	Fixed sum;
	
	sum.setRawBits(this->fixedPointValue + toassign.getRawBits());
	return(sum);
}

Fixed Fixed::operator - (const Fixed &toassign) const
{
	Fixed sub;

	sub.setRawBits(this->fixedPointValue - toassign.getRawBits());
	return(sub);
}

Fixed Fixed::operator / (const Fixed &toassign) const
{
	Fixed div;

	div.fixedPointValue = ((this->fixedPointValue << this->binaryPoint) / toassign.getRawBits());
	return(div);
}

Fixed Fixed::operator * (const Fixed &toassign) const
{
	Fixed prod;

	prod.setRawBits((this->fixedPointValue * toassign.getRawBits()) >> this->binaryPoint);
	return(prod);
}

Fixed  Fixed::operator ++ ()
{
	this->fixedPointValue += 1;
	return(*this);
}

Fixed	Fixed::operator ++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator -- ()
{
	this->fixedPointValue -= 1;
	return(*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed & Fixed::min(Fixed &x, Fixed &y)
{ 
	return (x < y ? x : y);
}

const Fixed & Fixed::min(const Fixed &x, const Fixed &y)
{
	return (x < y ? x : y);
}

Fixed & Fixed::max(Fixed &x, Fixed &y)
{
	return (x > y ? x : y);
}

const Fixed & Fixed::max(const Fixed &x, const Fixed &y)
{
	return (x > y ? x : y);
}