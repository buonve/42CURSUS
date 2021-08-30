/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:27:16 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/30 09:27:16 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float triangleArea(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) 
{
	return (std::abs((p1x * (p2y-p3y) + p2x * (p3y - p1y) + p3x * (p1y - p2y)) / 2.0));
}

bool bsp(Point a, Point b, Point c, Point x)
{

	float area = triangleArea (a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	float area1 = triangleArea (x.getX(), x.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	float area2 = triangleArea (a.getX(), a.getY(), x.getX(), x.getY(), c.getX(), c.getY());
	float area3 = triangleArea (a.getX(), a.getY(), b.getX(), b.getY(), x.getX(), x.getY());
	std::cout << "Area:  " << area << std::endl;
	std::cout << "Area1: " << area1 << std::endl;
	std::cout << "Area2: " << area2 << std::endl;
	std::cout << "Area3: " << area3 << std::endl;
	std::cout << "SUM:   " << area1 + area2 + area3 << std::endl;
	
   return (area == area1 + area2 + area3);
}
