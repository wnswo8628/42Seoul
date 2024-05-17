# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 21:25:50 by jugwak            #+#    #+#              #
#    Updated: 2023/03/09 17:06:09 by jugwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Werror -Wextra -Wall
HEADER = push_swap.h
RM = rm
RMFLAG = -f
SRCS = choose_op.c ft_split.c get_str_size.c min_max.c numarray.c operation_utils.c operation.c \
pb_best.c push_swap.c simple_sort.c stack_utils.c util.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all