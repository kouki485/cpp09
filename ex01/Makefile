NAME	= RPN

SRCS	= main.cpp\
			RPN.cpp

OBJS		= $(SRCS:%.c=%.o)

CXX			= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all		: $(NAME)

$(NAME)	: $(SRCS)
		$(CXX) $(CFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(NAME)

re : fclean all

test :
	./RPN "89 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "77 * 7 -"
	./RPN "(1 + 1)"

.PHONY : all clean fclean re