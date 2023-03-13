#include "BitcoinExchange.hpp"

std::string trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n")
{

	std::string result;
	std::string::size_type left = string.find_first_not_of(trimCharacterList);
	if (left != std::string::npos)
	{
		std::string::size_type right = string.find_last_not_of(trimCharacterList);
		result = string.substr(left, right - left + 1);
	}
	return (result);
}

int calcMaxDay(int i_year,int i_month)
{
	if (i_year % 4 == 0 && i_month == 2)//うるう年
		return (29);
	else
	{
		if ((i_month <= 7 && i_month % 2 == 1) ||(i_month >= 8 && i_month % 2 == 0))//３０か３１かを判定
			return (31);
		else if (i_month == 2)
			return (28);
		else
			return (30);
	}
	return (0);//ここに到達する事はない
}

size_t xStrlen(char *str)
{
	if(!str)
		return (0);
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	validateDate(std::string s_date, int &i_year,int &i_month,int &i_day)
{
	char 	*c_p_year;
	char 	*c_p_month;
	char 	*c_p_day;
	

	c_p_year = strtok(const_cast<char*>(s_date.c_str()), "-");

	if (c_p_year == NULL)
		return (ERROR);
	c_p_year = (char *)trim(c_p_year).c_str();
	if (xStrlen(c_p_year) != 4 || atoi(c_p_year) > MAX_YEAR || atoi(c_p_year) < MIN_YEAR )
		return (ERROR);
	else
		i_year = atoi(c_p_year);

	c_p_month = strtok(NULL, "-");
	if (c_p_month == NULL)
		return (ERROR);
	c_p_month = (char *)trim(c_p_month).c_str();
	if (xStrlen(c_p_month) != 2 || atoi(c_p_month) > MAX_MONTH || atoi(c_p_month) < MIN_MONTH)
		return (ERROR);
	else
		i_month = atoi(c_p_month);
	c_p_day = strtok(NULL, "-");
	if (c_p_day == NULL)
		return (ERROR);
	c_p_day = (char *)trim(c_p_day).c_str();
	if (xStrlen(c_p_day) != 2 || atoi(c_p_day) > calcMaxDay(i_year, i_month) || atoi(c_p_day) < MIN_DAY)
		return (ERROR);
	else
		i_day = atoi(c_p_day);
	return (SUCCESS);
}

bool isNumberArray(char *value_char_array)
{
	int i = 0;
	while(value_char_array[i])
	{
		if(isnumber(value_char_array[i] - '0'))
			return (ERROR);
		i++;
	}
	if (value_char_array[i - 1] == '.')//最後が.の場合をはじく
			return (ERROR);
	return (SUCCESS);
}

size_t countPipe(std::string input_file_line)
{
	size_t i = 0;
	size_t pipe_num = 0;
	for(;input_file_line[i];i++)
		if(input_file_line[i] == '|')
			pipe_num++;
	return (pipe_num);
}

bool splitLine(std::string input_file_line,Map &map)
{
	std::string s_date;
	float 		f_value;
	char		*date_char_array;
	char		*value_char_array;
	float		f_mult_res;
	int			i_year;
	int			i_month;
	int			i_day;
	std::string with_zero_month = "";
	std::string with_zero_day = "";
	std::map<std::string,std::string>::iterator its;

	if(countPipe(input_file_line) > 1)
	{
		std::cout << "Error: too many pipes." << std::endl;
		return (ERROR);
	}
	date_char_array = strtok(const_cast<char*>(input_file_line.c_str()), "|");
	value_char_array = strtok(NULL, "|");
	s_date = std::string(date_char_array);
	if (validateDate(s_date, i_year, i_month, i_day))
	{
		std::cout << "Error: bad input => " << s_date << std::endl;
		return (ERROR);
	}
	date_char_array = strtok(const_cast<char*>(input_file_line.c_str()), "|");
	if (value_char_array == NULL)
	{
		std::cout << "Error: bad input => " << s_date << std::endl;
		return (ERROR);
	}
	else
	{
		if(isNumberArray(value_char_array))
		{
			std::cout << "Error: value is not a number." << std::endl;
			return (ERROR);
		}
		else
			f_value = atof(value_char_array);
		if (f_value == 0)
		{
			std::cout << "Error: value is not a float or a positive integer between 0 and 1000. " << std::endl;
			return (ERROR);
		}
		else if ( f_value < 0)
		{
			std::cout << "Error: not a positive number. " << std::endl;
			return (ERROR);
		}
		else if (f_value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			return (ERROR);
		}
	}
	its = map.data.find(trim(s_date));
	if(its != map.data.end())
		f_mult_res = f_value * atof(its->second.c_str());
	else
	{
		std::cout << "Error: not found data in csv." << std::endl;
			return (ERROR);
	}
	if(1 <= i_month && i_month <= 9)
		with_zero_month = "0";
	if(1 <= i_day && i_day <= 9)
		with_zero_day = "0";
	std::cout << i_year << "-" << with_zero_month << i_month << "-" << with_zero_day << i_day << " => " << f_value << " = " << f_mult_res << std::endl;
	return (SUCCESS);
}

bool validateArgs(int argc)
{
	if (argc == 1)
	{
		std::cout << "Error: could not open file.\n";
		return (ERROR);
	}
	if (argc != 2)
	{
		std::cout <<"Error: num of arguments is invalid\n";
		return (ERROR);
	}
	return (SUCCESS);
}


bool	validateFirstLine(std::ifstream &input_file)
{
	std::string s_input_file_line;

	std::getline(input_file, s_input_file_line, '\n');
	if (strcmp(s_input_file_line.c_str(), "date | value") != 0)
	{
		std::cout << "Error: file's first line is not 'date | value'." << std::endl;
		return (ERROR);
	}
	return (SUCCESS);
}
