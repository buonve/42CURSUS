#include <iostream>
#include <fstream> 
#include <string.h>

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
        str.erase(start_pos, from.length());
		str.insert(start_pos, to);
        start_pos += to.length();
    }
}

int main (int ac, char **av)
{
	std::ifstream file;

	if(ac < 2)
	{
		std::cout << "Error" << std::endl;
		return (0);
	}
	if(ac == 4)
	{
		file.open(av[1]);
		if(!file)
		{
			std::cout << "File " << av[1] << " does not exists" << std::endl;
			return(0);
		}
		std::string buff;
		std::string str;
		while(std::getline(file ,buff))
			str.append(buff);
		replaceAll(str, av[2], av[3]);
		std::string new_name = av[1];
		new_name.append(".replace");
		std::ofstream file_out (new_name.c_str());
		file_out << str << std::endl;
		file_out.close();
		return(0);
	}
	std::cout << "Wrong argument number" << std::endl;
	return(0);
}