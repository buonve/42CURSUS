#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

class NotFoundException: public std::exception
{
	virtual const char* what() const throw()
	{
		return("EXCEPTION: Element not found!");
	}
};

template<class T>

typename T::iterator easyfind(T &cont, int pos)
{
	typename T:: iterator iter;
	iter = std::find(cont.begin(), cont.end(), pos);
	if (iter == cont.end())
		throw NotFoundException();
	return (iter);
}

#endif