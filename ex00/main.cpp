#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::map<std::string, int> map_bit_coin_csv;
	std::string				   s_input_file_line;

	if (validateArgs(argc))
		return (-1);
	std::ifstream input_file(argv[1]);
	if (!input_file)
	{
		std::cout << "Error: cannot open to file." << std::endl;
		return (-1);
	}
	if (validateFirstLine(input_file))
		return (-1);
	while (std::getline(input_file, s_input_file_line, '\n'))
	{
		splitLine(s_input_file_line);
	}
	return (0);

}