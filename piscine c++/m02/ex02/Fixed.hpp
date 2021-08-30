/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 14:42:28 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/29 18:38:35 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed( const int num );
		Fixed( const float flt );
		~Fixed();
		Fixed & operator= (const Fixed &toassign);
		bool operator > (const Fixed &toassign) const;
		bool operator < (const Fixed &toassign) const;
		bool operator >= (const Fixed &toassign) const;
		bool operator <= (const Fixed &toassign) const;
		bool operator == (const Fixed &toassign) const;
		bool operator != (const Fixed &toassign) const;
		Fixed operator + (const Fixed &toassign) const;
		Fixed operator - (const Fixed &toassign) const;
		Fixed operator / (const Fixed &toassign) const;
		Fixed operator * (const Fixed &toassign) const;
		Fixed operator ++ ();
		Fixed operator ++(int);
		Fixed operator -- ();
		Fixed operator --(int);
		static Fixed & min(Fixed &x, Fixed &y);
		const static Fixed & min(const Fixed &x, const Fixed &y);
		static Fixed & max(Fixed &x, Fixed &y);
		const static Fixed & max(const Fixed &x, const Fixed &y);
		int getRawBits( void ) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		

	private:
		int fixedPointValue;
		static const int binaryPoint = 8;
};

		std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif