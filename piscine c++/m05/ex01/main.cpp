/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:55:52 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:52 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat myBur("Ambrogio", 100);
	Form myForm("FormularioVini", 10, 15);
	
	try
	{
		myBur.raiseGrade(50);
		std::cout << myBur << std::endl;
		myBur.raiseGrade(40);
		std::cout << myBur << std::endl;
		myForm.signForm(myBur);
		std::cout << myForm << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}

	Bureaucrat Frakkio("Frakkio", 1);
	Form	Frakk_form("Frakk Form", 1, 2);
	try
	{
		Frakkio.reduceGrade(2);
		std::cout << Frakkio << std::endl;
		Frakk_form.signForm(Frakkio);
		std::cout << Frakk_form << std::endl;

	}
	catch(std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}
}