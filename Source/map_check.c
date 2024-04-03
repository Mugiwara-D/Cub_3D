/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:45:09 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/03 16:33:07 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_adjacent(t_game *game, char **map, int i, int j)
{
	if (i < game->map_lines - 1 && j < game->maxcol - 1)
		if ((map[i + 1][j] != ' ' && map[i + 1][j] != '1')
			|| (map[i][j + 1] != ' ' && map[i][j + 1] != '1'))
			return (1);
	if (i > 0 && j > 0)
		if ((map[i - 1][j] != ' ' && map[i - 1][j] != '1')
			|| (map[i][j - 1] != ' ' && map[i][j - 1] != '1'))
			return (1);
	return (0);
}

int	rectmap_check(t_game *game)
{
	int	i;
	int	j;

	game->map_lines = strs_len(game->rectmap);
	game->maxcol += 2;
	i = -1;
	while (++i < game->map_lines)
	{
		j = -1;
		while (++j < game->maxcol)
			if (game->rectmap[i][j] == ' ')
			{
				if (check_adjacent(game, game->rectmap, i, j))
					return (1);
			}
	}
	return (0);
}
