/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:14 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/03 18:59:21 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_strs(char **strs1, char **strs2, char *strs3[4])
{
	char	**strs;
	int		i;

	if (strs1)
	{
		strs = strs1;
		while (*strs)
			free(*(strs++));
		free(strs1);
	}
	if (strs2)
	{
		strs = strs2;
		while (*strs)
			free(*(strs++));
		free(strs2);
	}
	if (strs3)
	{
		i = 0;
		strs = strs3;
		while (i < 4 && strs[i])
			free(strs[i++]);
	}
}

void	free_all(t_game *game)
{
	clean_strs(game->rectmap, 0, game->text_paths);
	if (game->config)
		free(game->config);
	if (game->map)
		free(game->map);
	close(game->fd);
	free(game);
}

void	init_zero(t_game *game, char *argv)
{
	int	i;

	game->config = NULL;
	game->rectmap = NULL;
	game->map = NULL;
	game->maxcol = 0;
	game->map_lines = 0;
	game->conf_lines = 0;
	game->color_ceiling = 0;
	game->color_floor = 0;
	game->nplayer = 0;
	game->px = 0;
	game->py = 0;
	game->angle = 0;
	game->text_w = 0;
	game->text_idx = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->argv = argv;
	game->fd = 0;
	i = -1;
	while (++i < 4)
	{
		game->text_paths[i] = NULL;
		game->text[i].img = NULL;
	}
}

int	arg_check(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Synthax should be : ./cub3d path_to_map.cub\n"), 1);
	if (ft_strlen(argv[1]) < 5)
		return (printf("Invalid map file\n"), 1);
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub"))
		return (printf("Map sould be a .cub file\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (arg_check(argc, argv))
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (printf("failed to malloc structure\n"), 1);
	init_zero(game, argv[1]);
	if (read_init(game))
		return (free_all(game), 1);
	if (read_map(game))
		return (free_all(game), 1);
	if (!game->map)
		return (free_all(game), 1); //failed malloc
	if (map_check(game))
		return (free_all(game), 1);
	if (start_game(game))
		return (free_all(game), 1);
	free_all(game);
	return (0);
}