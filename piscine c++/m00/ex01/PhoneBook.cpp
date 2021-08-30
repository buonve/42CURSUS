
#include "PhoneBook.hpp"

std::string check_width(std::string str)
{
	int i = str.length();
	std::string modded;

	modded = str;
	if(i >= 9)
	{
		modded = modded.substr(0, 10);
		modded[9] = '.';
		return(modded);
	}
	return(modded);
}

void PhoneBook::search(int i, int j)
{
	std::string id;

	std::cout << std::setw(10) << "ID";
	std::cout << "|";	
	std::cout << std::setw(10) << "NAME";
	std::cout << "|";
	std::cout << std::setw(10) << "SURNAME";
	std::cout << "|";
	std::cout << std::setw(10) << "NICK";
	std::cout << "|" << std::endl;
	if(j)
	{
		for(int x = 0; x < j; x++)
		{
			std::cout << std::setw(10) << x;
			std::cout << "|";
			std::cout << std::setw(10) << check_width(user[x].getter("name"));
			std::cout << "|";
			std::cout << std::setw(10) << check_width(user[x].getter("surname"));
			std::cout << "|";
			std::cout << std::setw(10) << check_width(user[x].getter("nickname"));
			std::cout << "|" << std::endl;
		}
	}
	else
	{
		for(int x = 0; x < i; x++)
		{
			std::cout << std::setw(10) << x;
			std::cout << "|";
			std::cout << std::setw(10) << check_width(user[x].getter("name"));
			std::cout << "|";
			std::cout << std::setw(10) << check_width(user[x].getter("surname"));
			std::cout << "|";
			std::cout << std::setw(10) << check_width(user[x].getter("nickname"));
			std::cout << "|" << std::endl;
		}
	}

	std::cout << "Type the ID to get more details: ";
	std::cin >> id;
	if(!isdigit(id[0]) && atoi(id.c_str()) <= i)
		return;
	int num = atoi(id.c_str());
	//if(num < i && num < 0)
	//	return ;
	if(j)
	{
		if(num <= j)
		{
			std::cout << "Name: " << user[num].getter("name") << std::endl;
			std::cout << "Last Name: " << user[num].getter("surname") << std::endl;
			std::cout << "Nickname: " << user[num].getter("nickname") << std::endl;
			std::cout << "Phone Number: " << user[num].getter("number") << std::endl;
			std::cout << "Darkest Secret: " << user[num].getter("secret") << std::endl;
		}
	}
	else
	{
		if(num <= i)
		{
			std::cout << "Name: " << user[num].getter("name") << std::endl;
			std::cout << "Last Name: " << user[num].getter("surname") << std::endl;
			std::cout << "Nickname: " << user[num].getter("nickname") << std::endl;
			std::cout << "Phone Number: " << user[num].getter("number") << std::endl;
			std::cout << "Darkest Secret: " << user[num].getter("secret") << std::endl;
		}
	}
}

int PhoneBook::add_contact(int i)
{
	std::string value;
	std::cout << "Name: ";
	std::cin >> value;
	this->user[i].setter("name", value);
	std::cout << "Surname: ";
	std::cin >> value;
	this->user[i].setter("surname", value);
	std::cout << "Nickname: ";
	std::cin >> value;
	this->user[i].setter("nickname", value);
	std::cout << "Phone Number: ";
	std::cin >> value;
	this->user[i].setter("number", value);
	std::cout << "Darkest Secret: ";
	std::cin >> value;
	this->user[i].setter("secret", value);
	
	return (i + 1);
}
