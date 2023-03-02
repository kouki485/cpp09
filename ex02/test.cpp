#include <iostream>
#include <libc.h>

int main(int ac,char **av)
{
	for(int i = 0;av[1][i];i++)
	{
		if(!isdigit((int)av[1][i]))
		{
			std::cerr << "Error";
			return 0;
		}
		else
			std::cout << av[1][i];
	}
}