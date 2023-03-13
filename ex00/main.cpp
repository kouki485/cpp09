#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	Map 		csv_map;
	std::string	s_input_file_line;

	try
	{
		readCsv(csv_map);
		if (validateArgs(argc))
			return (0);
		std::ifstream input_file(argv[1]);
		if (!input_file)
		{
			std::cout << "Error: could not open file." << std::endl;
			return (0);
		}
		if (validateFirstLine(input_file))
			return (0);
		while (std::getline(input_file, s_input_file_line, '\n'))
		{
			splitLine(s_input_file_line,csv_map);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);

}