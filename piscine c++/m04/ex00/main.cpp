/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:23 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:23 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "j is a: " << j->getType() << " " << std::endl;
	std::cout << "i is a: " << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "***********************************************" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongCat *wcat = new WrongCat();

	std::cout << wcat->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	wcat->makeSound();
	wrong->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wcat;
	delete wrong;
}