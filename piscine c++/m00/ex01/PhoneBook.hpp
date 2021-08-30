#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
# include "Contacts.hpp"

class PhoneBook
{
	public:
		int	add_contact(int i);
		void	search(int i, int j);
	private:
		Contacts user[8];
};

#endif