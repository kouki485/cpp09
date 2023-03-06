#include "BitcoinExchange.hpp"

BitData::BitData(size_t date,size_t value){this->date = date; this->value = value;}
void BitData::set_date(size_t date){this->date = date;}
void BitData::set_value(size_t value){this->value = value;}
size_t BitData::get_date() const{	return (this->date);}
size_t BitData::get_value() const{	return (this->value);}
BitData::BitData(BitData const &c){*this = c;}
BitData::~BitData(){};

BitData &BitData::operator=(const BitData &rhs)
{
	if(this != &rhs)
	{
		this->date = rhs.date; 
		this->value = rhs.value;
	}
	return *this;
}

std::deque<std::string> split(const std::string& str, char delimiter)
{
	std::deque<std::string> tokens;
	std::istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

// void parse(std::string s)
// {
	
// }
// void func(char **argv)
// {

// }