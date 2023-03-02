NAME	= PmergeMe

SRCS	= main.cpp\
			PmergeMe.cpp

OBJS		= $(SRCS:%.c=%.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

all		: $(NAME)

$(NAME)	: $(SRCS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
