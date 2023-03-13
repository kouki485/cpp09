NAME	= RPN

SRCS	= main.cpp\
			RPN.cpp

OBJS		= $(SRCS:%.c=%.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

all		: $(NAME)

$(NAME)	: $(SRCS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(NAME)

re : fclean all

test :
	./$(NAME) "89 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "77 * 7 -"
	./$(NAME) "(1 + 1)"
	./$(NAME) "      * -  - - -+    "
	./$(NAME) "7"
	./$(NAME) "3 4 + 1 2 - *"
	./$(NAME) "2 3 /"
	./$(NAME) "3 2 /"
	./$(NAME) "0 2 /"
	./$(NAME) "2 0 /"
.PHONY : all clean fclean re test
