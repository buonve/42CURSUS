/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:55:50 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:50 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

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
		~Form();
		Form& operator= (const Form& form);
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		const int &getSignRight() const;
		const int &getExecRight() const;
		const std::string &getName() const;
		const bool &getSignStatus() const;
		void signForm(const Bureaucrat &myBur);
};

std::ostream& operator<<(std::ostream& out, const Form& form_status);

#endif