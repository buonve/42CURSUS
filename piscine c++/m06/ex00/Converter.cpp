/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:21:02 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 12:21:02 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter() {};

Converter::Converter(std::string value)
{
	this->value = value;
}

Converter::Converter(const Converter &cpy)
{
	this->value = cpy.getValue();
}

std::string Converter::getValue() const
{
	return(this->value);
}


Converter &Converter::operator=(Converter &cpy)
{
	this->value = cpy.getValue();
	return(*this);
}

float Converter::toFloat()
{
	return(atof(getValue().c_str()));
}

int Converter::toInt()
{
	return(static_cast<int>(toFloat()));
}

char Converter::toChar()
{
	char converted = static_cast<char>(toFloat());
	return(converted);
}

double Converter::toDouble()
{
	return(static_cast<double>(toFloat()));
}

void Converter::convert()
{
	/* PRINT CHAR VALUE */

	if(toFloat() < CHAR_MIN || toFloat() > CHAR_MAX || isnan(toFloat()))
		std::cout << "Char: Impossible" << std::endl;
	else if(isprint(toChar()))
		std::cout << "Char: " << toChar() << std::endl;
	else
		std::cout << "Char: Not displayable" << std::endl;

	/* PRINT INT VALUE */

	if(toInt() <= INT_MIN || toInt() >= INT_MAX || isnan(toInt()))
		std::cout << "Int: Impossible" << std::endl;
	else
		std::cout << "Int: " << toInt() << std::endl;
	
	/* PRINT FLOAT AND DOUBLE VALUE */

	if (toFloat() - toInt() == 0)
	{
		std::cout << "Float: " << toFloat() << ".0" << "f" << std::endl;
		std::cout << "Double: " << toDouble() << ".0"<< std::endl;
	}
	else
	{
		std::cout << "Float: " << toFloat() << "f" << std::endl;
		std::cout << "Double: " << toDouble() << std::endl;
	}
}


