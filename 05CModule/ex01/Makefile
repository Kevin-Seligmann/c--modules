FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

CC = c++

NAME = traps

OBJ = main.o Bureaucrat.o Form.o

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
