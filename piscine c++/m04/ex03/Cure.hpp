/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:34 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:34 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &cure);
		Cure &operator=(const Cure &cure);
		~Cure();
		Cure *clone() const;
		void use(ICharacter& target);
};

#endif