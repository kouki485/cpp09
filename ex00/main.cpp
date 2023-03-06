#include "BitcoinExchange.hpp"

size_t count_pipe(std::string s)
{
	size_t i = 0;
	size_t n = 0;
	for(;s[i];i++)
		if(s[i] == '|')
			n++;
	return n;
}

size_t tokenize(std::string const &str, const char* delim,
		std::deque<std::string> &out)
{
	char *token = strtok(const_cast<char*>(str.c_str()), delim);
	size_t i = 0;
 	while (token != NULL)
	{
		out.push_back(std::string(token));
		token = strtok(NULL, delim);
		i++;
	}
	return i;
}

int main(int argc,char **argv)
{
	BitData v(2008,1);
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
	std::deque<std::string> tmp,tmp2;
	size_t i = 0;
	while(getline(file,s))
	{
		tmp.push_back(s);
		i++;//行数
	}
	tmp2 = tmp;
	size_t k = 0;
	std::deque<std::string> value;
	// std::cout << l << std::endl;

	long l = 0;

	while(k < i)
	{
		if(count_pipe(tmp[k]) != 1)
		{
			std::cerr << "Error: bad input => " << tmp[k] << std::endl;
			k++;
		}
		tokenize(tmp2[k],"|",value);
		std::cout << tmp[k] << std::endl;
		k++;
	}
	
		for(size_t i = 0;value[i].c_str();i++)
		{
			l = atol(value[i].c_str());
			std::cout << l << std::endl;
			// if(l == 0 && i > 1)
			// 	std::cerr << "Error: not a number." << std::endl;

		}

	file.close();
	return 0;
}