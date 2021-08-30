/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:42:31 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/30 11:44:53 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point check(100, 150);

	if(bsp(a, b, c, check) == true)
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;
	return(0);
}