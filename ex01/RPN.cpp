#include "RPN.hpp"

static bool is_operator(char c)
{
	return(c == '+' || c == '-' ||c == '*' ||c == '/');
}

void error()
{
	std::cerr << "Error\n";
	exit(0);//make fileの都合
}

void parse(char **argv)
{
	std::stack<long long> st;

	size_t i = 0;
	size_t operator_count = 0;
	size_t count = 0;
	size_t num_count = 0;

	if(is_operator(argv[1][0]))
		error();
	for(size_t a = 0;argv[1][a];a++)
		if(is_operator(argv[1][a]))
			count++;
	if(strlen(argv[1]) == count)
		error();
	
	while(argv[1][i])
	{
		if(isspace(argv[1][i]))
		{
			// 最後の文字に達したらbreak
			i++;
			if((strlen(argv[1]) - 1) == --i)
				break ;
		}
		else if(argv[1][i] == '+' && st.size() >= 2)
		{
			long long k = st.top();
			st.pop();
			k += st.top();
			if(k > INT_MAX || k < INT_MIN)
				error();
			st.pop();
			st.push(k);
			operator_count++;
		}
		else if(argv[1][i] == '-' && st.size() >= 2)
		{
			long long l = st.top();
			st.pop();
			l = st.top() - l;
			if(l > INT_MAX || l < INT_MIN)
				error();
			st.pop();
			st.push(l);
			operator_count++;
		}
		else if(argv[1][i] == '*' && st.size() >= 2)
		{	
			long long m = st.top();
			st.pop();
			m *= st.top();
			if(m > INT_MAX || m < INT_MIN)
				error();
			st.pop();
			st.push(m);
			operator_count++;
		}
		else if(argv[1][i] == '/' && st.size() >= 2)
		{
			long long n = st.top();
			st.pop();
			if(n == 0)
				error();
			n = st.top() / n;
			st.pop();
			st.push(n);
			operator_count++;
		}
		else
		{
			int d = argv[1][i] - '0';
			if(0 <= d && d <= 9)
			{
				size_t tmp = i;
				if(argv[1][++tmp] == '\0')
					error();
				while (isspace(argv[1][tmp]))
				{
					if (argv[1][tmp + 1] == '\0')
						error();
					tmp++;
				}
				st.push(d);
				num_count++;
			}
			else
				error();
		}
		i++;
	}
	if(!operator_count || operator_count != (num_count - 1))
		error();
	while(st.size())
	{
	 std::cout << st.top();
	 st.pop();
	}
	std::cout << std::endl;
}
