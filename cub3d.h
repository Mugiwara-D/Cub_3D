/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:26:29 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/05 04:30:57 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define M_PI 3.14159265358979323846

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364

# define KEY_Q				113
# define KEY_ESC  			65307

# define WIDTH		640
# define HEIGHT		480
# define ROT_SPEED		0.02f
# define MV_SPEED	0.3f
# define FOV			1.047f // Field Of Vision 60 degrees

typedef struct s_sprite
{
	void	*xpm;
	int		x;
	int		y;
}	t_sprite;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;

}	t_rgb;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	horhit_x;
	float	horhit_y;
	float	verthit_x;
	float	verthit_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

typedef struct s_game
{
	char		**rectmap;
	char		*text_paths[4];
	char		*config;
	char		*map;
	char		*argv;
	int			fd;
	int			maxcol;
	int			map_lines;
	int			conf_lines;
	int			color_ceiling;
	int			color_floor;

	int			nplayer;
	float		px;
	float		py;
	float		angle;
	float		text_w;
	int			text_idx;

	void		*mlx;
	void		*win;
	t_img		img;
	t_img		text[4];

}	t_game;

void	clean_strs(char **strs1, char **strs2, char *strs3[4]);
int		read_init(t_game *game);
int		save_conf(t_game *game, char **strs);
int		is_empty(char *line);
int		read_map(t_game *game);
char	**split_w_space(t_game *game, int wd, char c);
char	*fill_w_space(int len);
int		map_check(t_game *game);
int		rectmap_check(t_game *game);
int		start_game(t_game *game);
int		terminate(t_game *game);
int		key_handler(int keycode, t_game *game);
void	ft_move(t_game *game, int direction);
float	ft_ray(t_game *game, float v);
void	ft_ray_casting(t_game *game);
void	ft_redraw(t_game *game);
void	ft_line(t_game *game, int w, float dist);
int		get_sign(float f);
int		set_color(t_game *game, char *rgb, char c, int *k);
int		shet_color(t_game *game, char **rgb, char c, int *k);
int		set_path(t_game *game, char *path, int index, int *k);
void	free_mem(t_game *game, int i);

#endif