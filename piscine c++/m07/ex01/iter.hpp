/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:34:44 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 15:34:44 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<class T>
void show_element(const T &element)
{
	std::cout << element << std::endl;
}

template<class T>
void iter(T *addr, int len, void(*f)(const T &arr_element))
{
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

#endif