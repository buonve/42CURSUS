/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:08:45 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:08:46 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap Giovanni("Giovanni");
	DiamondTrap Giuseppe("Giuseppe");
	DiamondTrap Gertrude("Gertrude");
	DiamondTrap Gaia("Gaia");

	for(int i = 0; i < 13; i++)
	{
		if(!Giuseppe.isDead())
		{
			Giovanni.attack(Giuseppe.getName());
			Giuseppe.takeDamage(Giovanni.getAttackDamage());
		}
	}
	Gertrude.beRepaired(100);
	Gaia.takeDamage(100);
	Giuseppe.highFivesGuys();
	Gertrude.whoAmI();
	Gaia.whoAmI();
	Giovanni.whoAmI();
	Giovanni.whoAmI();
}