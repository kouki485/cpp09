#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>

void func(char **argv);
#include <deque>

class BitData
{
	private:
		size_t date;
		size_t value;
	public:
		void set_date(size_t date);
		void set_value(size_t value);
		size_t get_date() const;
		size_t get_value() const;
		BitData(size_t date,size_t value);
		BitData &operator=(const BitData &rhs);
		BitData(BitData const &c);
		~BitData();
};

std::deque<std::string> split(const std::string& str, char delimiter);
#endif
