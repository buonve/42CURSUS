/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:08:39 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 12:08:39 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		virtual ~DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap operator = (const DiamondTrap &op);
		DiamondTrap(const DiamondTrap &cop);
		void set_protected_name(const std::string name);
		void whoAmI();
		void attack(const std::string &target);
	protected:
		std::string Name;
};

#endif