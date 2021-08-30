/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:15 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:15 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &dog);
		Dog(std::string &type);
		Dog &operator=(const Dog &dog);
		void makeSound() const;
		void setIdea(unsigned int i, const std::string &idea);
		std::string getIdea(unsigned int i) const;
	private:
		Brain *dog_brain;
};


#endif