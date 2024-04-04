/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:55:45 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/05 01:32:00 by xacharle         ###   ########.fr       */
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

int	check_configline(char *line)
{
	int		i;

	i = 0;
	while (strchr(" \t", line[i]))
		i++;
	printf("i = %d, line in check = %s\n", i, line);
	if (line[i] && line[i] != '\n')
		if (ft_strncmp(line + i, "NO", 2) && ft_strncmp(line + i, "SO", 2)
			&& ft_strncmp(line + i, "WE", 2) && ft_strncmp(line + i, "EA", 2)
			&& ft_strncmp(line + i, "F", 1) && ft_strncmp(line + i, "C", 1))
			return (printf("invalid or missing line in config\n"), 1);
	return (0);
}

static int	read_conf(t_game *game)
{
	int		i;
	char	*line;

	game->fd = open(game->argv, O_RDONLY);
	if (game->fd == -1)
		return (printf("couldn't open map file\n"), 1);
	line = get_next_line(game->fd);
	i = 0;
	while (line && i < 6)
	{
		printf("i = %d, line in read_conf = %s\n", i, line);
		if (!is_empty(line))
		{
			game->config = gnl_strjoin(game->config, line);
			i++;
		}
		if (check_configline(line))
			return (free(line), 1);
		free(line);
		if (i == 6)
			break ;
		line = get_next_line(game->fd);
	}
	return (0);
}

int	read_init(t_game *game)
{
	char	**strs;

	if (read_conf(game))
		return (1);
	if (!game->config)
		return (1);
	printf("config = %s\n", game->config);
	strs = ft_split(game->config, '\n');
	if (!strs)
		return (1);
	if (save_conf(game, strs))
		return (clean_strs(strs, 0, 0), 1);
	clean_strs(strs, 0, 0);
	return (0);
}
