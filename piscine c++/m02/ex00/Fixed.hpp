/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:17:58 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/30 14:17:58 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed & operator= (const Fixed &toassign);
		int getRawBits( void ) const;

	private:
		int rawBits;
		static const int binaryPoint = 8;
};

#endif