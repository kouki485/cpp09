#include "RPN.hpp"

int is_operator(char c)
{
	if(c == '+' || c == '-' ||c == '*' ||c == '/')
		return 1;
	return 0;
}

void error()
{
	std::cerr << "Error\n";
	exit(1);
}

void parse(char **argv)
{
	std::stack<int> st;

	size_t i = 0;
	size_t flag = 0;

	while(argv[1][i])
	{
		if(isspace(argv[1][i]))
			i++;
		if(!isascii(argv[1][i]))
			return ;
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
				st.push(d);
			else
				error();
		}
		i++;
	}
	if(flag == 0)
		error();
	while(st.size())
	{
	 std::cout << st.top();
	 st.pop();
	}
	std::cout << std::endl;
}