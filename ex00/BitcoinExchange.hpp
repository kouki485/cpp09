#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <deque>
#include <stdlib.h>

#define MAX_YEAR 2023
#define MIN_YEAR 2008
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MIN_DAY 1
#define ERROR 1
#define SUCCESS 0

bool validateArgs(int argc);
bool validateFirstLine(std::ifstream &input_file);
bool splitLine(std::string input_file_line);

#endif
