#include "Karen.hpp"

int main()
{
	Karen logs;
	logs.complain("DEBUG");
	logs.complain("INFO");
	logs.complain("WARNING");
	logs.complain("ERROR");

	logs.complain("ERROR");
	logs.complain("WARNING");
	logs.complain("INFO");
	logs.complain("DEBUG");

	logs.complain("ERROR");
	logs.complain("CIAO");
	logs.complain("ERROR");
	logs.complain("CIAO");
	return(0);
}