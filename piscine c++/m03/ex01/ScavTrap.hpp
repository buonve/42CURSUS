/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:59:23 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/01 11:59:24 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cop);
		virtual ~ScavTrap();
		ScavTrap operator = (const ScavTrap &op);
		void attack(std::string const & target);
		void guardGate();
	private:
		bool gatekeeper;
};

#endif


/*
			private		protected	public
private			x			x			x
protected	private		protected	protected
public		private		protected	public

*/