#include "Zombie.hpp"

int main()
{
	int 		N = 14;
	Zombie 		*frst_ptr;
	std::string	name;
	name.assign("Giovanni");

	frst_ptr = zombieHorde(N, name);
	for(int i = 0; i < N; i++)
		frst_ptr[i].announce();
	delete [] frst_ptr;
	return(0);
}