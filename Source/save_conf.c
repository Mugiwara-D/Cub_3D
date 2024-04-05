/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:57:38 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/05 11:03:21 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	set_colors(t_game *game, char **rgb, int *k)
{
	if (strs_len(rgb) == 2)
	{
		if (!ft_strcmp(rgb[0], "C"))
		{
			if (set_color(game, rgb[1], 'C', k))
				return (printf("2\n"), 1);
		}
		else if (!ft_strcmp(rgb[0], "F"))
			if (set_color(game, rgb[1], 'F', k))
				return (printf("3\n"), 1);
	}
	else if (strs_len(rgb) > 2)
	{
		if (!ft_strcmp(rgb[0], "C"))
		{
			if (shet_color(game, rgb, 'C', k))
				return (printf("4\n"), 1);
		}
		else if (!ft_strcmp(rgb[0], "F"))
			if (shet_color(game, rgb, 'F', k))
				return (printf("5\n"), 1);
	}
	else
		return (1);
	return (0);
}

static int	set_paths(t_game *game, char **tmp, int *k)
{
	if (!ft_strcmp(tmp[0], "WE") && game->text_paths[0] == NULL)
	{
		if (set_path(game, tmp[1], 0, k))
			return (1);
	}
	else if (!ft_strcmp(tmp[0], "SO") && game->text_paths[1] == NULL)
	{
		if (set_path(game, tmp[1], 1, k))
			return (1);
	}
	else if (!ft_strcmp(tmp[0], "EA") && game->text_paths[2] == NULL)
	{
		if (set_path(game, tmp[1], 2, k))
			return (1);
	}
	else if (!ft_strcmp(tmp[0], "NO") && game->text_paths[3] == NULL)
	{
		if (set_path(game, tmp[1], 3, k))
			return (1);
	}
	return (0);
}

static int	identify_and_save(t_game *game, char **tmp, int *k)
{
	if (!ft_strcmp(tmp[0], "C") || !ft_strcmp(tmp[0], "F"))
	{
		if (set_colors(game, tmp, k))
			return (printf("1\n"), 1);
	}
	else if (!ft_strcmp(tmp[0], "WE") || !ft_strcmp(tmp[0], "SO")
		|| !ft_strcmp(tmp[0], "EA") || !ft_strcmp(tmp[0], "NO"))
	{
		if (set_paths(game, tmp, k))
			return (1);
	}
	else
		return (printf("unknown argument in conf, should be NO, SO, WE, EA,\
			C and F\n"), 1);
	return (0);
}

int	check_duplicates(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = i;
		while (++j < 4)
		{
			if (!ft_strcmp(game->text_paths[i], game->text_paths[j]))
				return (printf("same textures found within diff params\n"), 1);
		}
	}
	if (game->color_ceiling == game->color_floor)
		return (printf("Ceiling and Floor have the same color\n"), 1);
	return (0);
}

int	save_conf(t_game *game, char **strs)
{
	int		i;
	int		k;
	char	**tmp;

	i = -1;
	k = 0;
	while (strs[++i])
	{
		tmp = ms_split(strs[i], " \t");
		if (!tmp)
			return (printf("failed malloc :( \n"), 1);
		if (strs_len(tmp) != 2
			&& (!ft_strcmp(tmp[0], "WE") || !ft_strcmp(tmp[0], "SO")
				|| !ft_strcmp(tmp[0], "EA") || !ft_strcmp(tmp[0], "NO")))
			return (printf("invalid config\n"), clean_strs(tmp, 0, 0), 1);
		if (identify_and_save(game, tmp, &k))
			return (clean_strs(tmp, 0, 0), 1);
		clean_strs(tmp, 0, 0);
	}
	if (k != 6)
		return (printf("invalid number of configuration args \n"), 1);
	if (check_duplicates(game))
		return (1);
	return (0);
}
