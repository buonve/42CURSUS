/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:53:54 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 11:56:23 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string & nick);
		ClapTrap(const ClapTrap &cop);
		~ClapTrap();
		ClapTrap operator = (const ClapTrap &op);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getAttackDamage() const;
		std::string getName() const;
		bool isDead();
	private:
		std::string Name;
		unsigned int Hitpoints;
		unsigned int Energypoints;
		unsigned int AttackDamage;
};

#endif