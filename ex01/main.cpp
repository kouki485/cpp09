#include "RPN.hpp"

//What is RPN?
// "3 4 +" -> "3 + 4"
// "3 4 + 1 2 - *" -> "(3 + 4) * (1 - 2)"


//"89 * 9 - 9 - 9 - 4 - 1 +"
//"(8 * 9) - 9 - 9 - 9 - 4 + 1 " = 42

//"77 * 7 -" -> "(7 * 7) - 7" = 42

int main(int argc,char **argv)
{
	if(argc != 2 || !strlen(argv[1]))
		error();
		parse(argv);
}
