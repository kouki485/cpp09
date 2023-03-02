#include "PmergeMe.hpp"

double calcTime()
{
	struct::timespec getTime;
	clock_gettime(CLOCK_MONOTONIC, &getTime);
	return (getTime.tv_sec + getTime.tv_nsec*1e-9) *1000;
}

int main(int argc,char **argv)
{
	if(argc == 1)
		error();
	func(argc,argv);
	//system("leaks PmergeMe");
	return 0;
}

//./PmergeMe $(jot -r -s " " 3000 1 1000000);
