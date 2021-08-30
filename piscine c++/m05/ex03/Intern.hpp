/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:56:15 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:56:15 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "Form.hpp"

class Intern
{
	private:
		std::string _formName;
		std::string _formTarget;
	public:
		Intern();
		~Intern();
		class FormNotFound : public std::exception
		{
			virtual const char* what() const throw();
		};
		Form *makeForm(std::string formName, std::string formTarget);
};

#endif