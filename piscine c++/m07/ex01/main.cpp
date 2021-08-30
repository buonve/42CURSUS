/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:34:43 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 15:34:43 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main ()
{
	int arr[] = {1, 2, -100, +5678765, 0};
	iter<int>(arr, 5, show_element);

	std::cout << "\n\n";

	std::string test = "CIAO VALUTATORE";
	iter<const char>(test.c_str(), 15, show_element);
}