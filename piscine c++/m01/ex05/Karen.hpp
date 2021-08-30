/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:42:05 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/28 14:42:05 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP
#include <iostream>

class Karen;
typedef void (Karen::*karen_func)(void);

class Karen
{
	public:
		void complain( std::string level );
		Karen();
		~Karen();
	private:
		std::string levels[4];
		karen_func f[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif