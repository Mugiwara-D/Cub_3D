/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:55:45 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/02 21:54:27 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isprint(line[i]) && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	read_conf(t_game *game)
{
	int		i;
	char	*line;
	char	*conf;

	game->fd = open(game->argv, O_RDONLY);
	if (game->fd == -1)
		return (1);
	conf = NULL;
	line = NULL;
	line = get_next_line(game->fd);
	i = 0;
	while (line && i < 6)
	{
		printf("line in read_conf= %s\n", line);
		if (!is_empty(line))
		{
			conf = gnl_strjoin(conf, line);
			i++;
		}
		free(line);
		if (i == 6)
			break ;
		line = get_next_line(game->fd);
	}
	game->cubfile = conf;
	return (0);
}

int	read_init(t_game *game)
{
	char	**strs;

	read_conf(game);
	if (!game->cubfile)
		return (1);
	printf("cubfile = %s\n", game->cubfile);
	strs = ft_split(game->cubfile, '\n');
	if (!strs)
		return (1);
	if (save_conf(game, strs))
		return (1);
	return (0);
}
