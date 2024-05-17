NAME = so_long
CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs
INCLUDES = solong.h
SRCS = check.c dfs.c get_next_line.c get_next_line_utils.c image.c main.c move.c openmap.c utils.c itoa.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o : $(SRCS)
	$(CC) $(CFLAG) -c $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	make all

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $@ $^ -L./mlx -lmlx -framework OpenGL -framework Appkit