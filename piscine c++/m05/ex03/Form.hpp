/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:28 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:28 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int exe_priv;
		const int sign_priv;
	public:
		Form();
		Form(std::string name, int exeRight, int signRight);
		Form(const Form& form);
		virtual ~Form();
		Form& operator= (const Form& form);
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};
		const int &getSignRight() const;
		const int &getExecRight() const;
		const std::string &getName() const;
		const bool &getSignStatus() const;
		void beSigned(const Bureaucrat &myBur);
		void beExecute(const Bureaucrat &executor) const;
		virtual void execute() const = 0;
};

std::ostream& operator<<(std::ostream& out, const Form& form_status);

#endif