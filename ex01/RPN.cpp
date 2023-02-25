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
	std::stack<int> st;

	size_t i = 0;
	size_t flag = 0;
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
			i++;
			if((strlen(argv[1]) - 1) == --i)
				break ;
		}
		else if(argv[1][i] == '+' && st.size() != 1)
		{
			int k = st.top();
			st.pop();
			k += st.top();
			st.pop();
			st.push(k);
			flag++;
		}
		else if(argv[1][i] == '-' && st.size() != 1)
		{
			int l = st.top();
			st.pop();
			l = st.top() - l;
			st.pop();
			st.push(l);
			flag++;
		}
		else if(argv[1][i] == '*' && st.size() != 1)
		{	
			int m = st.top();
			st.pop();
			m *= st.top();
			st.pop();
			st.push(m);
			flag++;
		}
		else if(argv[1][i] == '/' && st.size() != 1)
		{
			int n = st.top();
			st.pop();
			n = st.top() / n;
			st.pop();
			if(n == 0)
				error();
			st.push(n);
			flag++;
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
	if(!flag || flag != (num_count - 1))
		error();
	while(st.size())
	{
	 std::cout << st.top();
	 st.pop();
	}
	std::cout << std::endl;
}
