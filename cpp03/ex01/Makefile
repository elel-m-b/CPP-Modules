CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ClapTrap.cpp main.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = ex01

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all