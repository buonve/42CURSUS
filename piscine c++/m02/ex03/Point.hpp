/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:18:27 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/30 14:18:27 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		~Point();
		Point(const Point &pnt);
		Point(const Fixed &x, const Fixed &y);
		Point & operator = (const Point &pnt);
		float getX() const;
		float getY() const;
		void setX(Fixed const x);
		void setY(Fixed const y);
	private:
		const Fixed x;
		const Fixed y;
};

bool bsp(Point a, Point b, Point c, Point x);

#endif