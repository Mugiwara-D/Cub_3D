/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:57:38 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/03 18:44:45 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
// static int	identify_and_save(t_game *game, char **tmp, int *k)
// {
// 	if (!ft_strcmp(tmp[0], "C"))
// 	{
// 		if (set_color(game, tmp[1], 'C', k))
// 			return (1);
// 	}
// 	else if (!ft_strcmp(tmp[0], "F"))
// 	{
// 		if (set_color(game, tmp[1], 'F', k))
// 			return (1);
// 	}
// 	else if (!ft_strcmp(tmp[0], "WE") && game->text_paths[0] == NULL)
// 	{
// 		if (set_path(game, tmp[1], 0, k))
// 			return (1);
// 	}
// 	else if (!ft_strcmp(tmp[0], "SO") && game->text_paths[1] == NULL)
// 	{
// 		if (set_path(game, tmp[1], 1, k))
// 			return (1);
// 	}
// 	else if (!ft_strcmp(tmp[0], "EA") && game->text_paths[2] == NULL)
// 	{
// 		if (set_path(game, tmp[1], 2, k))
// 			return (1);
// 	}
// 	else if (!ft_strcmp(tmp[0], "NO") && game->text_paths[3] == NULL)
// 	{
// 		if (set_path(game, tmp[1], 3, k))
// 			return (1);
// 	}
// 	else
// 		return (1);
// 	return (0);

// static int	set_color(t_game *game, char *rgb, char c, int *k)
// {
// 	int	i;
// 	t_rgb	set;

// 	i = 0;
// 	set.r = mini_atoi(&rgb, &i);
// 	if (set.r == -1)
// 		return (1);
// 	set.g = mini_atoi(&rgb, &i);
// 	if (set.g == -1)
// 		return (1);
// 	set.b = mini_atoi(&rgb, &i);
// 	if (set.b == -1)
// 		return (1);
// 	if (c == 'C')
// 		game->color_ceiling = (set.r << 16) | (set.g << 8) | set.b;
// 	else
// 		game->color_floor = (set.r << 16) | (set.g << 8) | set.b;
// 	(*k)++;
// 	return (0);
// }
// }

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
		return (1);
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
		// printf("strs[%d] = %s\n", i, strs[i]);
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
	return (0);
}