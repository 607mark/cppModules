NAME := megaphone

RM := rm -rf

CC := c++
FLAGS := -Wall -Werror -Wextra -std=c++17

SRC := megaphone.cpp

OBJ := $(SRC:.cpp=.o)

all: $(NAME)

re: fclean all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all re
.PHONY: clean fclean