/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:21 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:21 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "Form.hpp"
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
		std::string 	_name;
		int 			_grade;
	public:
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& myBur);
		Bureaucrat& operator= (const Bureaucrat& myBur);
		~Bureaucrat();
		const std::string &getName() const;
		int getGrade() const;
		void raiseGrade(int value);
		void reduceGrade(int value);
		void executeForm(Form const & form);
		void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif