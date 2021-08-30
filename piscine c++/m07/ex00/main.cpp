/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:12:51 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 15:12:51 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "awesome.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;

	std::cout << "********** SIMPLE TEST INT **********" << std::endl;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;

	std::cout << "********** SIMPLE TEST STRING **********" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;

	Awesome e(100);
	Awesome f(50);

	std::cout << "********** COMPLEX TEST CLASS **********" << std::endl;
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << max( e, f ) << std::endl;

	return (0);
}