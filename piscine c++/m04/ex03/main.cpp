/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:46 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:46 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* giovanni = new Character("Giovanni");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	giovanni->equip(tmp);
	tmp = src->createMateria("cure");
	giovanni->equip(tmp);
	tmp = src->createMateria("ice");
	giovanni->equip(tmp);
	tmp = src->createMateria("cure");
	giovanni->equip(tmp);
	tmp = src->createMateria("ice");
	giovanni->equip(tmp);
	tmp = src->createMateria("cure");
	giovanni->equip(tmp);

	ICharacter* pastello = new Character("Pastello");

	giovanni->use(0, *pastello);
	giovanni->use(1, *pastello);
	giovanni->use(0, *pastello);
	giovanni->use(1, *pastello);
	giovanni->use(2, *pastello);
	giovanni->use(3, *pastello);
	//std::cout << "WEEEE" << std::endl;

	Character luca("Luca"), pasqualo("Pasqualo");

	tmp = src->createMateria("ice");
	luca.equip(tmp);
	luca = pasqualo;
	luca.use(0, pasqualo);
	pasqualo.use(0, luca);

	delete pastello;
	delete giovanni;
	delete src;
	return 0;
}