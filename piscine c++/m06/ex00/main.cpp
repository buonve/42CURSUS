/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:21:07 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 12:21:07 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Converter value(av[1]);
		value.convert();
	}
	else
		std::cout << "Error: Wrong arg number" << std::endl;
	return(0);
}