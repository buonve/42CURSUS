/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:02 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:02 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(std::string &type);
		Animal(const Animal& pet);
		void operator=(const Animal &op);
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
		virtual void setIdea(unsigned int i, const std::string &idea) = 0;
		virtual std::string	getIdea(unsigned int i) const = 0;

	protected:
		std::string type;
};

#endif