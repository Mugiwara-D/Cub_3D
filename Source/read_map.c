/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:37:53 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/03 16:32:38 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	rect_map(t_game *game)
{
	int	w;

	w = wd_count(game->map, '\n');
	game->rectmap = malloc(sizeof(char *) * (w + 3));
	if (!game->rectmap)
		return (1); //failed malloc
	game->rectmap[0] = fill_w_space(game->maxcol + 2);
	if (!game->rectmap[0])
		return (1);
	game->rectmap[w + 1] = fill_w_space(game->maxcol + 2);
	if (!game->rectmap[w + 1])
		return (1);
	game->rectmap = split_w_space(game, w + 1, '\n');
	if (!game->rectmap)
		return (1);
	return (0);
}

static int	imposter_check(t_game *game)
{
	int	i;
	int	player;

	i = -1;
	player = 0;
	while (game->map[++i])
	{
		if (ft_strchr("NSEW", game->map[i]))
			player++;
		else if (!ft_strchr(" 01\n", game->map[i]))
			return (1); //intruder character in the map
	}
	if (player != 1)
		return (1); //more than 1 player 
	return (0);
}

int	map_check(t_game *game)
{
	if (imposter_check(game))
		return (1); //invalid map
	if (rect_map(game))
		return (1);
	if (rectmap_check(game))
		return (1);
	return (0);
}

int	read_map(t_game *game)
{
	char	*line;
	int		maxcol;
	
	line = get_next_line(game->fd);
	if (!line)
		return (1); // no map or failed alloc?
	while (line && is_empty(line))
	{
		free(line);
		line = get_next_line(game->fd);
	}
	while (line)
	{
		if (is_empty(line))
			return (free(line), 1); //empty line in middle of map
		maxcol = ft_strlen(line);
		if (maxcol > game->maxcol)
			game->maxcol = maxcol - 1;
		game->map = gnl_strjoin(game->map, line);
		free(line);
		line = get_next_line(game->fd);
	}
	close(game->fd);
	return (0);
}
