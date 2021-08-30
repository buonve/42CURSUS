#include "Contacts.hpp"
#include <iostream>

void Contacts::setter(std::string type, std::string value)
{
	if(!type.compare("name"))
		this->name = value;
	else if(!type.compare("surname"))
		this->surname = value;
	else if(!type.compare("nickname"))
		this->nickname = value;
	else if(!type.compare("number"))
		this->number = value;
	else if(!type.compare("secret"))
		this->secret = value;
}

std::string Contacts::getter(std::string type)
{
	if(!type.compare("name"))
		return this->name;
	else if(!type.compare("surname"))
		return this->surname;
	else if(!type.compare("nickname"))
		return this->nickname;
	else if(!type.compare("number"))
		return this->number;
	else
		return this->secret;
	
}