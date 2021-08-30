/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:19 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:19 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &cp);
		~Dog();
		Dog &operator=(const Dog cp);
		Dog(std::string &type);
		void makeSound() const;
};

#endif