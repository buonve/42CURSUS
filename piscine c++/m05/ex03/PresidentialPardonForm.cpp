/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:33 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:33 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("president", 5, 25)
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const
{
	return(_target);
}

void PresidentialPardonForm::execute() const
{
	std::cout << "[" + getTarget() + "] has been pardoned by Lega Nord per Padania Libera (\"e queeeendeeeee\")." << std::endl;
}




