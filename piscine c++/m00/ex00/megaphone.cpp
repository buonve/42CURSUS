#include <iostream>

int main(int ac, char **av) {
	std::string str;
	int i = 1;

	if (ac > 1)
	{
		while (i < ac)
			str.append(av[i++]);
	}
	else
		str.assign("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	std::cout << str << std::endl;
	return 0;
}