NAME	= btc

SRCS	= main.cpp\
			BitcoinExchange.cpp\
			ReadCsv.cpp\

OBJS		= $(SRCS:%.c=%.o)

CXX			= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

all		: $(NAME)

$(NAME)	: $(SRCS)
		$(CXX) $(CXXFLAGS) -o $@ $^

clean	:

fclean	: clean
	rm -f $(NAME)

re : fclean all

test :
	./$(NAME) 
	./$(NAME) input.txt
.PHONY : all clean fclean re