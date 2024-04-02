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


typedef struct s_sprite
{
	void	*xpm;
	int		x;
	int		y;
}	t_sprite;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

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
	float	hor_x;
	float	hor_y;
	float	vert_x;
	float	vert_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

typedef struct s_game
{
	char		*cubfile;
	char		**testmap;
	char		**map;
	char		*text_paths[4];
	char		*argv;
	int			fd;
	int			ncol;
	int			nline;
	int			conf_lines;
	int			color_ceiling;
	int			color_floor;

	int			nplayer;
	float		px;
	float		py;
	float		angle;
	float		txt_w;
	int			txt_idx;

	void		*mlx;
	void		*win;
	t_img		img;
	t_img		text[4];

}	t_game;

#endif