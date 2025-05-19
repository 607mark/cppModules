NAME := animal
RM := rm -rf

# CC := c++
# FLAGS := -Wall -Werror -Wextra -std=c++20

CC := clang++
FLAGS := -Wall -Werror -Wextra -Winconsistent-missing-override -std=c++20

SRC := Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \
		Brain.cpp \
		main.cpp

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
