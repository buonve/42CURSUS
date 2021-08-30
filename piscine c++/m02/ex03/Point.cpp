/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:18:24 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/30 14:18:24 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
}

Point::Point(const Point &pnt)
{
	*this = pnt;
}

Point::Point(const Fixed &x, const Fixed &y)
{
	this->setX(x);
	this->setY(y);
}

Point::~Point()
{

}

Point & Point::operator = (const Point &pnt)
{
	this->setX(pnt.getX());
	this->setY(pnt.getY());
	return(*this);
}

float Point::getX() const 
{
	return x.getRawBits();
}

float Point::getY() const 
{
	return y.getRawBits();
}

void Point::setX(Fixed rpl_x) {
	((Fixed *)(&this->x))->setRawBits(rpl_x.getRawBits());
}

void Point::setY(Fixed rpl_y)
{
	((Fixed *)(&this->y))->setRawBits(rpl_y.getRawBits());
}
