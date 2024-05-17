/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:44:55 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 20:08:55 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17
# define E 3
# define W 1
# define S 2
# define N 0
# define WIDTH 640
# define HEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define K_A 0
# define K_B 11
# define K_C 8
# define K_D 2
# define K_E 14
# define K_F 3
# define K_G 5
# define K_H 4
# define K_I 34
# define K_J 38
# define K_K 40
# define K_L 37
# define K_M 46
# define K_N 45
# define K_O 31
# define K_P 35
# define K_Q 12
# define K_R 15
# define K_S 1
# define K_T 17
# define K_U 32
# define K_V 9
# define K_W 13
# define K_X 7
# define K_Y 16
# define K_Z 6 

# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125

# define K_NP_DIV 75
# define K_NP_MUL 67
# define K_NP_MIN 78
# define K_NP_PLU 69
# define K_NP_1	83
# define K_NP_2	84
# define K_NP_3	85
# define K_NP_4	86
# define K_NP_5	87
# define K_NP_6	88
# define K_NP_7	89
# define K_NP_8	91
# define K_NP_9	92

# define K_SP 49
# define K_ESC 53
# define K_TAB 48

# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

typedef struct s_raycast
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_tex
{
	int		texnum;
	double	wallx;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
}				t_tex;

typedef struct s_map
{
	char	**full_map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f_rgb;
	int		c_rgb;
	int		width;
	int		height;
	int		line_cnt;
	int		map_index;
}	t_map;

typedef struct s_player
{
	double	player_x;
	double	player_y;
	int		player_status;
}	t_player;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	double		move_speed;
	double		rot_speed;
	t_img		img;
	int			buf[HEIGHT][WIDTH];
	int			**texture;
	int			re_buf;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_ar_l;
	int			key_ar_r;
	int			key_esc;
	t_map		map;
	t_player	player;
}	t_info;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	char	type;
}	t_rgb;

int		ft_strlen(char *str);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_memset(void *ptr, int value, size_t num);
char	*ft_strcpy(char *dest, char *src);

void	map_check(t_map *map, char *line, t_player *player);
char	*check_path(char *line);
void	get_texture(char *line, t_map *map);
int		filename_check(char *filename);
void	line_check(char *line, t_map *map, t_player *player);

int		get_digit(char *line, int *i);
void	check_rgb(char *line);
void	get_rgb(char *line, t_map *map);

void	get_player_xy(char **str, t_player *player);
void	check_wall(t_map *map, char **str);
void	map_dup(int fd, t_map *map);
void	find_map(int fd, t_map *map);
void	map_parse(char *filename, t_map *map, t_player *player);

void	print_error(char *str);
int		ft_isspace(char c);
int		get_playerstatus(char c);
int		check_fc(char c, int i);
int		end_program(t_info *info);

void	init_tex(int **texture, int x, int y, int value);
void	init_key_value(t_info *info);
void	vec_init(t_info *info, int dir, int plane);
void	pos_value_init(t_info *info);
void	all_init(t_info *info);

void	get_image(t_info *info, int *texture, char *path, t_img *img);
void	set_image(t_info *info);

int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);

void	check_key(t_info *info);
void	change_sight(t_info *info, double dir);
void	press_ad(t_info *info, double dir);
void	press_ws(t_info *info, double dir);
void	draw_buffer(t_info *info);

void	raycasting(t_info *info);
void	get_perp(t_info *info, t_raycast *rc);
void	set_texture(t_info *info, t_raycast *rc, int x);
void	dda_algorithm(t_info *info, t_raycast *rc);
void	set_dda_vars(t_info *info, t_raycast *rc);

int		get_texnum(t_raycast *rc);
void	draw_texture(t_info *info, t_raycast *rc, t_tex *tex, int x);

void	set_color(t_info *info);
void	ft_free(t_info *info);

#endif