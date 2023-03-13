#include "BitcoinExchange.hpp"

Map::Map(){}
Map::~Map(){}
Map::Map(Map const &rhs){*this = rhs;}
Map &Map::operator=(Map const &rhs){(void)rhs; return *this;}

void splitByConnmaAndInsertMap(std::string s_line,Map &map)
{
	std::string s_year;
	std::string s_value;
	s_year = (std::string)strtok(const_cast<char*>(s_line.c_str()), ",");
	s_value = (std::string)strtok(NULL, ",");
	map.data.insert(std::make_pair(s_year,s_value));
}

void readCsv(Map &map)
{
	std::string s_line;
	std::ifstream file("./a.csv");
	while (std::getline(file, s_line))
	{
		splitByConnmaAndInsertMap(s_line,map);
	}
}
