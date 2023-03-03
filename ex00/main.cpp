#include "BitcoinExchange.hpp"

int main(int argc,char **argv)
{
	(void)**argv;
	BitData v(56,10);
	if(argc == 1)
	{
		std::cerr << "Error: could not open file.\n";
		return 0;
	}
	if(argc != 2)
	{
		std::cerr << "Error\n";
		return 0;
	}
	//func(&argv[1]);
	std::ifstream file(argv[1]);
	std::string s;
	while(getline(file,s))
	{}
	file.close();
	std::cout << s;
	return 0;
}