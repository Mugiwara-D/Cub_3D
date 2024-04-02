/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:36:14 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/02 04:12:15 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_strs(char **strs1, char **strs2, char **strs3)
{
	char	**strs;

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
		strs = strs3;
		while (*strs)
			free(*(strs++));
		free(strs3);
	}
}

void	init_zero(t_game *game, char *argv)
{
	int	i;

	game->cubfile = NULL;
	game->testmap = NULL;
	game->map = NULL;
	game->ncol = 0;
	game->nline = 0;
	game->conf_lines = 0;
	game->color_ceiling = 0;
	game->color_floor = 0;
	game->nplayer = 0;
	game->px = 0;
	game->py = 0;
	game->angle = 0;
	game->txt_w = 0;
	game->txt_idx = 0;
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
	int		fd;
	char	*line;

	if (argc != 2)
		return (printf("Synthax should be : ./cub3d path_to_map.cub\n"), 1);
	if (ft_strlen(argv[1]) < 5)
		return (printf("Invalid map file\n"), 1);
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub"))
		return (printf("Map sould be a .cub file\n"), 1);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (printf("failed to open map file\n"), 1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (printf("map file is empty \n"), 1);
	}
	close(fd);
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
	read_init(game);
}