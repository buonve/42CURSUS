/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:12:54 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 15:12:54 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>


template<class T>
void swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<class T>
T min(T &a, T &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<class T>
T max(T &a, T &b)
{
		if (a > b)
		return a;
	else
		return b;
}

#endif