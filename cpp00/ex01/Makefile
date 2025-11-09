CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp main.cpp PhoneBook.cpp 
OBJS = $(SRCS:.cpp=.o)

NAME = contact

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
