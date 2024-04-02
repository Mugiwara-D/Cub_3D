/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:43:32 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/02 19:53:29 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*fill_w_space(int len)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = ' ';
	str[i] = 0;
	return (str);
}

char	*substr_w_space(t_game *game, int start, int len)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (game->maxcol + 3));
	if (!str)
		return (NULL);
	str[0] = ' ';
	i = 1;
	while (len-- && start < (int)ft_strlen(game->map))
		str[i++] = game->map[start++];
	while (i < game->maxcol + 2)
		str[i] = ' ';
	str[i] = 0;
	return (str);
}

char	**split_w_space(t_game *game, int wd, char c)
{
	int		i;
	int		j;
	int		start;

	j = 1;
	i = 0;
	while (j < wd && game->map && game->map[i])
	{
		if (game->map[i] == c)
			i++;
		else
		{
			start = i;
			while (game->map[i] != c && game->map[i])
				i++;
			game->rectmap[j] = substr_w_space(game, start, i - start);
			if (!game->rectmap[j])
				return (clean_strs(game->rectmap, 0, 0), NULL);
			j++;
		}
	}
	game->rectmap[wd + 1] = NULL;
	return (game->rectmap);
}
