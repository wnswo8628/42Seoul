NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror
HEADER = pipex.h
SRC = pipex.c utils.c parse.c ft_split.c
OBJ = $(SRC:c=o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ)
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re bonus