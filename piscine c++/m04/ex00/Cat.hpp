/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:09:15 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:09:15 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &cp);
		~Cat();
		Cat &operator=(const Cat &cp);
		Cat(std::string &type);
		void makeSound() const;
};


#endif