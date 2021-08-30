/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:55:40 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:40 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat myBur("Ambrogio", 100);

	try
	{
		myBur.raiseGrade(50);
		std::cout << myBur << std::endl;
		//myBur.reduceGrade(150);
		//std::cout << myBur << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	Bureaucrat Frakkio("Frakkio", 120);
	try
	{
		//Frakkio.reduceGrade(31);
		std::cout << Frakkio << std::endl;
	}
	catch(std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	try
	{
		Bureaucrat Troppo("Troppo Broh", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
