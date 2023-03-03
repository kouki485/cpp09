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

// void func(char **argv)
// {

// }