/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:38 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:38 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotoMyRequestForm.hpp"
#include <cstdlib>

RobotoMyRequestForm::RobotoMyRequestForm() {}

RobotoMyRequestForm::RobotoMyRequestForm(std::string target):
Form("Robot", 45, 72)
{
	_target = target;
}

RobotoMyRequestForm::~RobotoMyRequestForm() {}

std::string RobotoMyRequestForm::getTarget() const
{
	return(_target);
}

void RobotoMyRequestForm::execute() const
{
	std::cout << "Beedo boop bop beeda beep boop lop bleeda bee bop bleeda booop bopp beedlaboop boooopppppp!!!!!!" << std::endl;
	bool TrueFalse = (rand() % 100) < 50;
	if(TrueFalse)
		std::cout << "[" + this->getTarget() + "] has been robotomized successfully." << std::endl;
	else
		std::cout << "[" + this->getTarget() + "] robotomized failed." << std::endl;
}
