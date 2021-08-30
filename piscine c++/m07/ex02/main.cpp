/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:12:17 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 18:12:17 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(int, char**)
{
	std::cout << "-----------INT ARRAY-----------" << std::endl;
	Array<int> alfa(3);
	alfa[0] = 1;
	alfa[1] = 2;
	alfa[2] = 3;

	Array<int> beta(alfa);
	Array<int> gamma(beta);

	std::cout << "alfa size:" << alfa.size() << std::endl;
	std::cout << "beta size:" << beta.size() << std::endl;
	std::cout << "gamma size:" << gamma.size() << std::endl << std::endl;

	try
	{
		alfa[0] = 42;
		beta[1] = 42;
		gamma[2] = 42;
		//gamma[100] = 9;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	for (unsigned int i = 0; i < alfa.size(); i++)
	{
		std::cout << "alfa[" << i << "]: " << alfa[i] << std::endl;
		std::cout << "beta[" << i << "]: " << beta[i] << std::endl;
		std::cout << "gamma[" << i << "]: " << gamma[i] << std::endl << std::endl;
	}

	std::cout << "-----------FLOAT ARRAY-----------" << std::endl;
	Array<float> alfa_f(3);
	alfa_f[0] = 1.1f;
	alfa_f[1] = 2.2f;
	alfa_f[2] = 3.3f;

	Array<float> beta_f(alfa_f);
	Array<float> gamma_f(beta_f);

	std::cout << "alfa size:" << alfa_f.size() << std::endl;
	std::cout << "beta size:" << beta_f.size() << std::endl;
	std::cout << "gamma size:" << gamma_f.size() << std::endl << std::endl;

	try
	{
		alfa_f[0] = 42.42f;
		beta_f[1] = 42.42f;
		gamma_f[2] = 42.42f;
		//gamma[100] = 9;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	for (unsigned int i = 0; i < alfa_f.size(); i++)
	{
		std::cout << "alfa[" << i << "]: " << alfa_f[i] << std::endl;
		std::cout << "beta[" << i << "]: " << beta_f[i] << std::endl;
		std::cout << "gamma[" << i << "]: " << gamma_f[i] << std::endl << std::endl;
	}

	std::cout << "-----------CHAR ARRAY-----------" << std::endl;
	Array<char> alfa_c(3);
	alfa_c[0] = 'a';
	alfa_c[1] = 'b';
	alfa_c[2] = 'c';

	Array<char> beta_c(alfa_c);
	Array<char> gamma_c(beta_c);

	std::cout << "alfa size:" << alfa_c.size() << std::endl;
	std::cout << "beta size:" << beta_c.size() << std::endl;
	std::cout << "gamma size:" << gamma_c.size() << std::endl << std::endl;

	try
	{
		alfa_c[0] = 'M';
		beta_c[1] = 'A';
		gamma_c[2] = 'O';
		//gamma[100] = 9;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	for (unsigned int i = 0; i < alfa_c.size(); i++)
	{
		std::cout << "alfa[" << i << "]: " << alfa_c[i] << std::endl;
		std::cout << "beta[" << i << "]: " << beta_c[i] << std::endl;
		std::cout << "gamma[" << i << "]: " << gamma_c[i] << std::endl << std::endl;
	}
}