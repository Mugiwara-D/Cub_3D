/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:22 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/03 16:33:37 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_sign(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}

void	ft_move(t_game *game, int direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = game->angle + direction * M_PI / 2;
	dx = LINEAR_STEP * cos(angle);
	dy = LINEAR_STEP * sin(angle);
	dist = ft_ray(game, ft_sign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = ft_ray(game, (1 - (ft_sign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	dist = ft_ray(game, angle);
	if (dist * dist < dy * dy + dx * dx)
		if (ft_sign(dy) * ft_sign(dx) != 0)
			dy = 0.0f;
	game->px += dx;
	game->py -= dy;
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_destroy_exit(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_move(game, 0);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_move(game, 2);
	else if (keycode == KEY_LEFT)
		game->angle -= ANGLE_STEP * M_PI;
	else if (keycode == KEY_RIGHT)
		game->angle += ANGLE_STEP * M_PI;
	else if (keycode == KEY_A)
		ft_move(game, 3);
	else if (keycode == KEY_D)
		ft_move(game, 1);
	else
		return (0);
	ft_redraw(game);
	return (0);
}
