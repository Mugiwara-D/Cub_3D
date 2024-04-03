/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:13:06 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/03 18:36:28 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	starting_angle(t_game *game, const char c)
{
	if (c == 'E')
		game->angle = 0.0f * M_PI;
	else if (c == 'N')
		game->angle = 0.5f * M_PI;
	else if (c == 'W')
		game->angle = 1.0f * M_PI;
	else if (c == 'S')
		game->angle = -0.5f * M_PI;
}

void	starting_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->maxcol)
	{
		j = -1;
		while (game->rectmap[i][++j])
		{
			if (ft_strchr("NSWE", game->rectmap[i][j]))
			{
				game->px = (float) j + 0.5f;
				game->py = (float) i + 0.5f;
				starting_angle(game, game->rectmap[i][j]);
				return ;
			}
		}
	}
}

void	ft_resoures_initialisation(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		game->text[i].img = mlx_xpm_file_to_image(game->mlx,
				game->text_paths[i], &game->text[i].width, &game->text[i].height);
		if (!game->text[i].img)
		{
			ft_dprintf(2, "Can't read file '%s'\n", game->text_paths[i]);
			ft_destroy_exit(game);
		}
		game->text[i].addr = mlx_get_data_addr(game->text[i].img,
				&game->text[i].bits_per_pixel, &game->text[i].line_length,
				&game->text[i].endian);
	}
}

int	ft_destroy_exit(t_game *game)
{
	int	i;

	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	i = -1;
	while (++i < 4)
		if (game->text[i].img)
			mlx_destroy_image(game->mlx, game->text[i].img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_all(game);
	exit(0);
}

int	start_game(t_game *game)
{
	starting_position(game);
	game->mlx = mlx_init();
	ft_resoures_initialisation(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	ft_redraw(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_key, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, ft_destroy_exit, game);
	mlx_loop(game->mlx);
	return (0);
}
