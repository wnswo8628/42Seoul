# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 03:19:50 by jugwak            #+#    #+#              #
#    Updated: 2023/07/10 20:09:27 by jugwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = cub3D
NAMEB = cub3D_bonus
CFLAGS = -Wall -Wextra -Werror
MLX = minilibx

SOURCES =	mandatory/check_key.c mandatory/file_check.c mandatory/get_rgb.c mandatory/init_info.c \
			mandatory/key_setting.c mandatory/main.c \
			mandatory/map_parse.c mandatory/raycasting_util.c mandatory/raycasting.c mandatory/set_image.c mandatory/utils.c \
			libft/ft_atoi.c libft/ft_isdigit.c libft/ft_memset.c libft/ft_strcmp.c \
			libft/ft_strcpy.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c \
			libft/ft_substr.c \
			get_next_line/ft_substr.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

BONUS =	bonus/check_key_bonus.c bonus/file_check_bonus.c bonus/get_rgb_bonus.c bonus/init_info_bonus.c \
		bonus/key_setting_bonus.c bonus/main_bonus.c bonus/map_parse_bonus.c bonus/raycasting_util_bonus.c \
		bonus/raycasting_bonus.c bonus/set_image_bonus.c bonus/utils_bonus.c \
		libft/ft_atoi.c libft/ft_isdigit.c libft/ft_memset.c libft/ft_strcmp.c \
		libft/ft_strcpy.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c \
		libft/ft_substr.c \
		get_next_line/ft_substr.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SOURCES:.c=.o)
OBJB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX)
	@cp minilibx/libmlx.a ./
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) libmlx.a

bonus: $(NAMEB)

$(NAMEB): $(OBJB)
	@make -C $(MLX)
	@cp minilibx/libmlx.a ./
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAMEB) $(OBJB) libmlx.a

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS) libmlx.a
	@rm -f $(OBJB)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAMEB)
	@make clean -C $(MLX)

re: fclean all

.PHONY : all, clean, fclean, re, bonus