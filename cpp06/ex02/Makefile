NAME = identify
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
