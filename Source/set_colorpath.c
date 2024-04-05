/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colorpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:02:00 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/05 12:29:07 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	mini_atoi(char **rgb, int *i)
{
	int	tmp;

	tmp = 0;
	while ((**rgb) && ft_isdigit(**rgb))
	{
		tmp = (tmp * 10) + **rgb - '0';
		if (tmp > 255)
			return (-1);
		(*rgb)++;
	}
	if (*i != 2 && **rgb != ',')
		return (-1);
	(*rgb)++;
	(*i)++;
	return (tmp);
}

int	set_color(t_game *game, char *rgb, char c, int *k)
{
	int		i;
	t_rgb	set;

	i = 0;
	if (!ft_isdigit(rgb[ft_strlen(rgb) - 1]))
		return (printf("invalid character in color config\n"), 1);
	set.r = mini_atoi(&rgb, &i);
	if (set.r == -1)
		return (1);
	set.g = mini_atoi(&rgb, &i);
	if (set.g == -1)
		return (1);
	set.b = mini_atoi(&rgb, &i);
	if (set.b == -1)
		return (1);
	if (c == 'C')
		game->color_ceiling = (set.r << 16) | (set.g << 8) | set.b;
	else
		game->color_floor = (set.r << 16) | (set.g << 8) | set.b;
	(*k)++;
	return (0);
}

int	shet_color(t_game *game, char **rgb, char c, int *k)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (rgb[++i])
		str = gnl_strjoin(str, rgb[i]);
	if (!ft_isdigit(str[ft_strlen(str) - 1]))
		return (printf("invalid character in color config\n"), free(str), 1);
	if (set_color(game, str, c, k))
		return (printf("7\n"), free(str), 1);
	free(str);
	return (0);
}

int	set_path(t_game *game, char *path, int index, int *k)
{
	if (ft_strlen(path) < 5)
		return (printf("Invalid xpm file\n"), 1);
	if (ft_strcmp(path + ft_strlen(path) - 4, ".xpm"))
		return (printf("xpm should be a .xpm file\n"), 1);
	if (ft_strncmp(path, "./", 2))
		return (printf("should be ./path_to_file.xpm\n"), 1);
	game->text_paths[index] = ft_strdup(path);
	if (!game->text_paths[index])
		return (printf("malloc failed :( \n"), 1);
	(*k)++;
	return (0);
}
