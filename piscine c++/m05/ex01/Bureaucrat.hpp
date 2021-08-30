/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:55:46 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:55:46 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

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
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat& operator= (const Bureaucrat& b);
		~Bureaucrat();
		const std::string &getName() const;
		int getGrade() const;
		void raiseGrade(int value);
		void reduceGrade(int value);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


#endif