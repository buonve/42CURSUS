/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:21:04 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 12:21:04 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <iostream>
#include <cmath>
#include <climits>

class Converter
{
	private:
		std::string value;
	public:
		Converter();
		Converter(std::string value);
		Converter(const Converter &cpy);
		Converter &operator=(Converter &cpy);
		std::string getValue() const;
		void convert();
		int toInt();
		char toChar();
		float toFloat();
		double toDouble();
		};

#endif