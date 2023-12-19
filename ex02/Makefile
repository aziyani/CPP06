NAME = Identify

CC = C++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Base.cpp A.cpp B.cpp C.cpp main.cpp

HFILE = Base.hpp A.hpp B.hpp C.hpp

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