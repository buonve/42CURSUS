/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:18 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:18 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog dog;
	Cat cat;
	Animal* animals[10];
	//Animal test;

	dog.setIdea(0, "Play");
	cat.setIdea(0, "Sleep");
	for (int i = 0; i < 2; i++){
		if (i % 2)
			animals[i] = new Cat(cat);
		else
			animals[i] = new Dog(dog);
	}
	std::cout << animals[0]->getIdea(0) << std::endl;
	std::cout << animals[1]->getIdea(0) << std::endl;
	animals[0]->setIdea(0, "Explore");
	animals[1]->setIdea(0, "Eat");
	std::cout << animals[0]->getIdea(0) << std::endl;
	std::cout << animals[1]->getIdea(0) << std::endl;
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << cat.getIdea(0) << std::endl;
	for (int i = 0; i < 2; i++)
		delete animals[i];
	return 0;
}