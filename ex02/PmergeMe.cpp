#include "PmergeMe.hpp"
void error()
{
	std::cerr << "Error\n";
	exit(0);//make fileの都合
}

void insertion_sort(std::list<size_t>& l)
{
	std::list<size_t>::iterator i, j, temp;
	for (i = ++l.begin(); i != l.end(); ++i)
	{
		temp = i;
		for (j = i; j != l.begin(); --j)
		{
			if (*temp > *(--j))
			{
				++j;
				break;
			}
			++j;
		}
		l.insert(j, *temp);
		l.erase(temp);
	}
}

void merge(std::vector<size_t>& v, size_t left, size_t mid, size_t right)
{

	std::vector<size_t> temp(right - left + 1);

	size_t i = left;
	size_t j = mid + 1;
	size_t k = 0;

	while (i <= mid && j <= right)
	{
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	}

	while (i <= mid)
		temp[k++] = v[i++];

	while (j <= right)
		temp[k++] = v[j++];
	std::copy(temp.begin(), temp.end(), v.begin() + left);
}

void merge_sort(std::vector<size_t>& v, size_t left, size_t right)
{

	if (left >= right) {	return;}

	size_t mid = (left + right) / 2;

	merge_sort(v, left, mid);
	merge_sort(v, mid + 1, right);

	merge(v, left, mid, right);
}

size_t tokenize(std::string const &str, const char* delim,
		std::vector<std::string> &out)
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

void my_sort(int argc,std::vector<size_t> vec,std::list<size_t> list,size_t j,bool flag2)
{
	size_t s = 0;
	std::cout << "After:\t";
	double start = calcTime();
	merge_sort(vec,0,vec.size() - 1);
	double end = calcTime();

	std::vector<size_t>::iterator it;
	for(it = vec.begin();it != vec.end();it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	if(flag2)
		s = j;
	else
		s = argc - 1;
	std::cout << std::setprecision(5) << "Time to process a range of "<< s << " elements with std::vector : " \
			<< end - start << " us.\n";

	double start1 = calcTime();
	insertion_sort(list);
	double end1 = calcTime();
	std::cout << std::setprecision(5) << "Time to process a range of "<< s << " elements with std::list   : " \
			<< end1 - start1 << " us.\n";
	
}


void func(int argc,char **argv)
{
	for(int i = 1;i < argc;i++)
		if(atol(argv[i]) < 0)
			error();
	std::list<size_t> list;
	std::vector<size_t> vec,test;
	std::vector<std::string> tmp;
	bool flag = true;
	bool flag2 = false;
	size_t j = 0;
	if(argc == 2)
	{
		flag2 = true;
		if(strlen(argv[1]) == 0)
				flag = false;
		size_t i = tokenize(argv[1],"\t\n\v\f\r' '",tmp);
		j = i;

		for(size_t u = 0;u < i;u++)
		{
			for(size_t k = 0;tmp[u][k];k++)
				if(!isdigit((size_t)tmp[u][k]))
					error();
			if(atol(tmp[u].c_str()) <= 0 || atol(tmp[u].c_str()) > INT_MAX)
				flag = false;
			vec.push_back(atol(tmp[u].c_str()));
			list.push_front(atol(tmp[u].c_str()));
		}
		if(flag == true)
		{
			std::cout << "Before:\t";
			for(size_t u = 0;u < i;u++)
				std::cout << " " << tmp[u].c_str();
		}
		else
		{
			vec.clear();
			list.clear();
			error();
		}
	}
	else
	{
		for(int i = 1;i < argc;i++)
		{
			for(size_t k = 0;argv[i][k];k++)
				if(!isdigit((size_t)argv[i][k]))
					error();
			if(atol(argv[i]) <= 0 || atol(argv[i]) > INT_MAX)
				flag = false;
			vec.push_back(atol(argv[i]));
			list.push_front(atol(argv[i]));
		}
		if(flag == true)
		{
			std::cout << "Before:\t";
			for(int i = 1;i < argc;i++)
				std::cout << " " << argv[i];
		}
		else
		{
			vec.clear();
			list.clear();
			error();
		}
	}
	std::cout << std::endl;
	my_sort(argc,vec,list,j,flag2);
}
