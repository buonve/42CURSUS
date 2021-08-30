/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:30 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:30 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include "Animal.hpp"

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &cp);
		WrongAnimal &operator=(const WrongAnimal &cp);
		std::string	getType() const;
		virtual void makeSound() const;
};

#endif
