/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:21:18 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/16 12:21:18 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
	std::string Prima;
	int			Durante;
	float		Dopo;
	char 		Finito;
} Data;

uintptr_t serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main()
{
	Data *ptr = new Data;

	std::cout << sizeof(*ptr) << std::endl;
	std::cout << "Address data: " << ptr << std::endl;
	std::cout << "Ptr : " << serialize(ptr) << std::endl;
	std::cout << "Address data: " << deserialize(serialize(ptr)) << std::endl;

	delete ptr;
	return (0);
}