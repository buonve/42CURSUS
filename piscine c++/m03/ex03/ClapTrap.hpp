/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:08:34 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:08:35 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const std::string & nick);
		ClapTrap();
		~ClapTrap();
		ClapTrap operator = (const ClapTrap &op);
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		bool isDead();
		void setHitPoint(unsigned int amount);
		void setEnergyPoint(unsigned int amount);
		void setAttackDamage(unsigned int amount);
		void setName(const std::string name);
		unsigned int getAttackDamage() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
	private:
		std::string Name;
		unsigned int Hitpoints;
		unsigned int Energypoints;
		unsigned int AttackDamage;
};

#endif