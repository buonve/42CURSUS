/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:30 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:30 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotoMyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat *bunga = new Bureaucrat("Berlusconi", 73);
	Bureaucrat *mela = new Bureaucrat("Meloni", 46);
	Bureaucrat *quende = new Bureaucrat("Salvene", 1);

	Form *top_secret = new PresidentialPardonForm("49 milioni €");
	Form *robotomy = new RobotoMyRequestForm("Dyson Vacuum 7500D");
	Form *shrubbery = new ShrubberyCreationForm("Casa in Montagna");

	std::cout << *shrubbery << std::endl;
	bunga->signForm(*shrubbery);
	bunga->executeForm(*shrubbery);
	mela->signForm(*shrubbery);
	mela->executeForm(*shrubbery);
	quende->signForm(*shrubbery);
	quende->executeForm(*shrubbery);

	std::cout << *robotomy << std::endl;
	bunga->signForm(*robotomy);
	bunga->executeForm(*robotomy);
	mela->signForm(*robotomy);
	mela->executeForm(*robotomy);
	quende->signForm(*robotomy);
	quende->executeForm(*robotomy);


	std::cout << *top_secret << std::endl;
	bunga->signForm(*top_secret);
	bunga->raiseGrade(72);
	bunga->executeForm(*top_secret);
	bunga->signForm(*top_secret);
	mela->signForm(*top_secret);
	quende->signForm(*top_secret);

	delete bunga;
	delete mela;
	delete quende;
	delete robotomy;
	delete shrubbery;
	delete top_secret;
}