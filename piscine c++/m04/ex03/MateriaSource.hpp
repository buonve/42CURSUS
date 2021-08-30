/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:12:51 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:12:51 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *learned[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource& source);
		MateriaSource& operator= (MateriaSource& source);
		void learnMateria(AMateria* amateria);
		AMateria* createMateria(std::string const & type);
};

#endif
