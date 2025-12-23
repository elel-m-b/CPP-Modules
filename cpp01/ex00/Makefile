NAME = ex00
SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
OBJS = $(SRCS:.cpp=.o)

hh = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(hh) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
