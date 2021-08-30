#include "Zombie.hpp"

int main()
{
	Zombie *z1;

	z1 = newZombie("Stegosandro");
	z1->announce();
	randomChump("Pollops");
	delete z1;
	return 0;
}