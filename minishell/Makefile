# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 13:07:27 by jugwak            #+#    #+#              #
#    Updated: 2023/05/13 19:11:27 by jugwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft
LIBFT_LIB = libft.a
CC = cc
CFLAGS = -Werror -Wextra -Wall
COMFILE_FLAGS = -lreadline -L/Users/jugwak/.brew/opt/readline/lib
OBJ_FLAGS = -I/Users/jugwak/.brew/opt/readline/include
RM = rm -f
LIBC = ar rc
SRCS = ./main.c ./outredirect.c ./parse.c ./split_q.c ./utils.c ./utils2.c ./check_syntax.c ./dq_split.c ./execute.c ./utils3.c\
		built_in/cd.c built_in/cd2.c built_in/echo.c built_in/env.c built_in/exit.c built_in/export.c built_in/export2.c built_in/pwd.c built_in/unset.c \
		cmd_parse/cmd_parse.c cmd_parse/delete_q.c cmd_parse/make_option.c cmd_parse/makecmd.c cmd_parse/parse_option.c cmd_parse/util.c \
		free/free_double.c free/free.c \
		heredoc/file_heredoc.c heredoc/heredoc_parse.c \
		libft/ft_strcmp.c \
		pipe/execve.c pipe/fork.c pipe/free_path.c pipe/open.c pipe/path.c pipe/std.c pipe/wait.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	mv $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -o $@

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re