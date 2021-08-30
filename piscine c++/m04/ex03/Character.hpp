/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:29 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:29 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include <iostream>

class Character: public ICharacter
{
	private:
		AMateria *inventory[4];
		std::string name;
	public:
		Character(const std::string &name);
		Character(Character& character);
		Character& operator= (Character& character);
		std::string const & getName() const;
		~Character();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif