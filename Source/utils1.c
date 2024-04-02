/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:55:45 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/02 04:36:01 by xacharle         ###   ########.fr       */
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

void	read_conf(t_game *game)
{
	int		i;
	char	*line;
	char	*conf;

	game->fd = open(game->argv, O_RDONLY);
	if (game->fd == -1)
		exit_handler(1, game);
	conf = NULL;
	line = get_next_line(game->fd);
	i = 0;
	while (line && i < 6)
	{
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
	if (line)
		free(line);
	game->cubfile = conf;
}

void	read_init(t_game *game)
{
	char	**strs;

	read_conf(game);
	if (!game->cubfile)
		exit_handler(2, game);
	strs = ft_split(game->cubfile, "\n");
	if (!strs)
		exit_handler(3, game);
	if (save_conf(game, strs))
		exit_handler(4, game);
}
