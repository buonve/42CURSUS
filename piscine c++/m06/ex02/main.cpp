/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:11:33 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 12:11:33 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>

Base * generate(void)
{
	srand (time(NULL));
	switch(rand() % 3)
	{
		case 0:
			std::cout << "Type A Created" << std::endl;
			return(new A);
		case 1:
			std::cout << "Type B Created" << std::endl;
			return(new B);
		case 2:
			std::cout << "Type C Created" << std::endl;
			return(new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if(dynamic_cast <A*>(p))
		std::cout << "Pointer Type: A" << std::endl;
	else if(dynamic_cast <B*>(p))
		std::cout << "Pointer Type: B" << std::endl;
	else if(dynamic_cast <C*>(p))
		std::cout << "Pointer Type: C" << std::endl;
	else
		std::cout << "Pointer Type: No Type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference Type : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Reference Type : B" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Reference Type : C" << std::endl;
		}
	}
}

int main ()
{
	Base *Type = generate();

	identify(Type);
	identify(*Type);
	delete Type;
	return (0);
}