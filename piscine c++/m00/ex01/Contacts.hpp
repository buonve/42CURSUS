#ifndef CONTACTS_HPP
# define CONTACTS_HPP
# include <string>
# include <iostream>

class Contacts
{
		std::string	name;
		std::string surname;
		std::string	nickname;
		std::string	number;
		std::string secret;
	public:
		void setter(std::string type, std::string value);
		std::string getter(std::string type);
};

#endif