/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:40 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:40 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
#include <iostream>

class RobotoMyRequestForm: public Form
{
	private:
		std::string _target;
	public:
		RobotoMyRequestForm();
		RobotoMyRequestForm(std::string target);
		~RobotoMyRequestForm();
		std::string getTarget() const;
		void execute() const;
};

#endif