/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:11:06 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/23 11:11:06 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &cp);
		~Brain();
		Brain& operator =(const Brain & op);
		std::string getIdea(unsigned int i) const;
		void setIdea(unsigned int i, const std::string &idea);
	private:
		std::string ideas[100];
};


#endif