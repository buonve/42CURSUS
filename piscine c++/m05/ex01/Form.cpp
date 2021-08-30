/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:55:48 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:48 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
name("ANON"),
exe_priv(-1),
sign_priv(-1)
{
	is_signed = false;
}

Form::Form(std::string name, int exeRight, int signRight):
name(name),
exe_priv(exeRight),
sign_priv(signRight)
{
	this->is_signed = false;
}

Form::Form(const Form& form):
name(form.getName()),
exe_priv(form.getExecRight()),
sign_priv(form.getSignRight())
{
	*this = form;
}

Form& Form::operator= (const Form& form)
{
	is_signed = form.getSignStatus();
	return *this;
}

Form::~Form() {}

const int &Form::getSignRight() const
{
	return(sign_priv);
}

const int &Form::getExecRight() const
{
	return(exe_priv);
}

const std::string &Form::getName() const
{
	return(name);
}

const bool &Form::getSignStatus() const
{
	return(is_signed);
}

std::ostream& operator<<(std::ostream& out, const Form& form_status)
{
	out << "Form [" + form_status.getName() + "] has privilege " << form_status.getSignRight() << " to sign and privilege " << form_status.getExecRight() << " to execute." << std::endl;
	return(out);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Exception: Bureaucrat cannot sign form because its grade is too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Exception: Bureaucrat cannot sign form because its grade is too Low");
}

void Form::signForm(const Bureaucrat &myBur)
{
	if(myBur.getGrade() > this->sign_priv)
		throw Form::GradeTooLowException();
	if(getSignStatus())
		std::cout << "Bureaucrat cannot sign form because it's already signed." << std::endl;
	else
	{
		this->is_signed = true;
		std::cout << "Bureaucrat [" + myBur.getName() + "] with grade " << myBur.getGrade() << " signed form [" + this->getName() + "] with minimum sign privilege grade of " << this->getSignRight() << std::endl;
	}
}



