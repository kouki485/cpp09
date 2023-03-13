#include "PmergeMe.hpp"

int main(int argc,char **argv)
{
	if(argc == 1)
		error();
	func(argc,argv);
	//system("leaks PmergeMe");
	return 0;
}

//./PmergeMe $(jot -r -s " " 3000 1 1000000);
