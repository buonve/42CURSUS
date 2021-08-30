/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:53:58 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 11:53:59 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Giovanni("Giovanni");
	ClapTrap Giuseppe("Giuseppe");
	ClapTrap Gertrude("Gertrude");
	ClapTrap Gaia("Gaia");

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
}