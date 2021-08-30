/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:10 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:10 by vbuonvin         ###   ########.fr       */
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
		Animal(Animal &pet);
		Animal &operator=(const Animal &an);
		virtual std::string getType() const;
		virtual void makeSound() const;

	protected:
		std::string type;
};

#endif