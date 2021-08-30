/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:59:18 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:00:45 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap Giovanni("Giovanni");
	ScavTrap Giuseppe("Giuseppe");
	ScavTrap Gertrude("Gertrude");
	ScavTrap Gaia("Gaia");

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
	Giuseppe.guardGate();
	Giuseppe.guardGate();
}