/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:11 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:11 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"


class Cat: public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &cat);
		Cat(std::string &type);
		Cat &operator=(const Cat &cat);
		void makeSound() const;
		void setIdea(unsigned int i, const std::string &idea);
		std::string getIdea(unsigned int i) const;
	private:
		Brain *cat_brain;
};


#endif