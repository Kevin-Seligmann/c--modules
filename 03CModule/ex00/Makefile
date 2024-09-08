FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

NAME = traps

OBJ = main.o ClapTrap.o

HDR = ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp $(HDR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
