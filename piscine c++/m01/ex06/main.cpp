#include "Karen.hpp"

int main(int ac, char **av)
{
	std::string level;
	Karen karen;

	if(ac != 2)
	{
		std::cout << "Wrong argument number" << std::endl;
		return(0);
	}
	level = av[1];
	karen.complain(level);
}