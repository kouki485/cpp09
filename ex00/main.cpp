#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	Map csv_map;
	std::string				   s_input_file_line;

	readCsv(csv_map);
	if (validateArgs(argc))
		return (-1);
	std::ifstream input_file(argv[1]);
	if (!input_file)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (-1);
	}
	if (validateFirstLine(input_file))
		return (-1);
	while (std::getline(input_file, s_input_file_line, '\n'))
	{
		splitLine(s_input_file_line,csv_map);
	}
	return (0);

}