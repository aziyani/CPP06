NAME = conversion

CC = C++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ScalarConverter.cpp main.cpp
HFILE =  ScalarConverter.hpp

OBJ = $(SRC:%.cpp=%.o)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HFILE)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all%