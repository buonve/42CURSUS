#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	std::string cmd;
	int i = 0;
	int rep;

	while(1)
	{
		std::cout << "Write Command: ";
		std::cin >> cmd;
		if(!cmd.compare("ADD"))
		{
			if(i <= 7)
				i = book.add_contact(i);
			else
			{
				std::cout << "No space left. Do you want to replace the oldest contact? YES/NO ";
				std::cin >> cmd;
				if(!cmd.compare("YES"))
				{
					rep = i % 8;
					book.add_contact(rep);
					i += 1;
				}
			}
		}
		else if(!cmd.compare("SEARCH"))
		{
			if(i > 7)
				book.search(i, 7);
			else
				book.search(i, 0);
		}
		else if(!cmd.compare("EXIT"))
			break ;
		else
			std::cout << "Command not found" << std::endl;
	}
	return 0;
}