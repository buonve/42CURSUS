/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:12:14 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 18:12:14 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <cstdlib>

template<class T>
class Array
{
	private:
		T *array;
		unsigned int len;
	public:
		Array() {
			array = NULL;
			len = 0;
		};
		Array(unsigned int n)
		{
			this->len = n;
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = 0;
		};
		
		const Array &operator=(const Array &arr)
		{
			if(arr.len)
				delete [] array;
			len = arr.len;
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				this->array[i] = arr.array[i];
			return(*this);
		};

		Array(Array &arr)
		{
			T *tempCopy;
			tempCopy = new T[arr.len];
			for (unsigned int i = 0; i < arr.len; i++)
				tempCopy[i] = arr.array[i];
			len = arr.len;
			this->array = tempCopy;
		};

		~Array() {
			delete [] array;
		};

		T &operator[](unsigned int i)
		{
			if(i > len || i < 0)
				throw Exception();
			return(this->array[i]);
		};

		unsigned int size()
		{
			return(this->len);
		};

		class Exception: public std::exception
		{
			virtual const char *what() const throw() {
				return("Exception: reading/writing out of array boundaries!");
			}
		};
};

#endif