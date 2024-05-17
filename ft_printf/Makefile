NAME = libftprintf.a
CC = gcc
CFALG = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = crs
INCLUDES = ./printf.h
SRCS = print_char.c print_hex.c print_num.c printf.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean 
	make all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
