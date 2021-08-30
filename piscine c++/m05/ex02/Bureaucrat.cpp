/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:18 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:18 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_name = name;
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& myBur)
{
	_grade = myBur.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& myBur) : _name(myBur.getName())
{
	*this = myBur;
}

Bureaucrat::~Bureaucrat() {}

const std::string & Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

void Bureaucrat::raiseGrade(int value)
{
	int test;
	if((test = this->getGrade() - value) < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade -= value;
}

void Bureaucrat::reduceGrade(int value)
{
	int test;
	if((test = this->getGrade() + value) > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += value;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Exception: Grade Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Exception: Grade Too Low!");
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& myBur)
{
	o << myBur.getName() << ", bureaucrat grade " << myBur.getGrade() << ".";
	return(o);
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.beExecute(*this);
		std::cout << "[" + getName() + "] executed [" + form.getName() + "] form" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[" + getName() + "] coudn't execute form [" + form.getName() + "] because: " + e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "[" + getName() + "] signed [" + form.getName() + "] form" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "[" + getName() + "] coudn't sign form [" + form.getName() + "] because: " + e.what() << std::endl;
	}
}
