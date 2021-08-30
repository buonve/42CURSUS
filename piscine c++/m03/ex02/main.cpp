/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:02:40 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:02:41 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap Giovanni("Giovanni");
	FragTrap Giuseppe("Giuseppe");
	FragTrap Gertrude("Gertrude");
	FragTrap Gaia("Gaia");

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
	
}