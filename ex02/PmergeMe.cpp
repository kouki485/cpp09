#include "PmergeMe.hpp"
void error()
{
	std::cerr << "Error\n";
	exit(0);//make fileの都合
}

#include <algorithm>
void my_sort(int argc,std::vector<int> vec)
{
	double start = calcTime();
	sort(vec.begin(),vec.end());
	double end = calcTime();

	std::vector<int>::iterator it;
	for(it = vec.begin();it != vec.end();it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << std::setprecision(5) << "Time to process a range of "<< argc - 1 << " elements with std::vector : " \
			<< end - start << " us.\n";
}

void func(int argc,char **argv)
{
	std::vector<int> vec;
	std::cout << "Before:\t";
	for(int i = 1;i < argc;i++)
	{
		std::cout << " " << argv[i];
		vec.push_back(atol(argv[i]));
	}
	std::cout << std::endl;
	std::cout << "After:\t";
	my_sort(argc,vec);
}

