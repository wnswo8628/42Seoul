/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:23:21 by jugwak            #+#    #+#             */
/*   Updated: 2023/02/22 19:39:42 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "mlx/mlx.h"

# define X_EVENT_KEY_EXIT 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define BUFFER_SIZE 1000

typedef struct s_gameinfo
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		height;
	int		width;
	int		c_player;
	int		c_collect;
	int		c_exit;
	int		countcollect;
	int		c_walk;
	int		player_x;
	int		player_y;
}	t_gameinfo;

typedef struct s_check
{
	char	**tempmap;
	int		check_collect;
	int		way;
	int		x;
	int		y;
}	t_check;

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*tile;
	int		img_width;
	int		img_height;
}	t_image;

char	*ft_strchr(char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line_file(char *sentense, char *files);
char	*read_file(int fd, char *files);
void	printerror(char *message);
void	errormessage(char *message);
void	move_w(t_gameinfo *gameinfo);
void	move_a(t_gameinfo *gameinfo);
void	move_s(t_gameinfo *gameinfo);
void	move_d(t_gameinfo *gameinfo);
void	checkwall(t_gameinfo *gameinfo);
void	elementcount(t_gameinfo *gameinfo);
void	check_rectangle(t_gameinfo *gameinfo);
void	findplayer(t_check *check, t_gameinfo *gameinfo);
void	makecheck(t_check *check, t_gameinfo *gameinfo);
void	dfs(t_check *check, t_gameinfo *gameinfo, int x, int y);
int		find_ber(char *mapfile, char *find);
int		checkfilename(char *mapfile);
void	insertmap(int fd2, t_gameinfo *gameinfo);
void	openmap(char *mapfile, t_gameinfo *gameinfo);
void	connect_image(t_gameinfo *gameinfo, t_image *image);
void	setting_image(t_gameinfo *gameinfo, t_image *image);
void	create_image(t_gameinfo *gameinfo);
void	correntplayer(t_gameinfo *gameinfo);
char	*ft_itoa(int n);
int		check_width(char *map);
char	*ft_strdup(const char *str);

#endif
