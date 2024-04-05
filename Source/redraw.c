/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:54:18 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/05 11:02:06 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_draw_ceiling_and_floor(t_game *game)
{
	unsigned int	*dst;
	unsigned int	i;

	dst = (unsigned int *) game->img.addr;
	i = WIDTH * HEIGHT / 2 + 1;
	while (--i > 0)
		*dst++ = game->color_ceiling;
	i = WIDTH * HEIGHT / 2 + 1;
	while (--i > 0)
		*dst++ = game->color_floor;
}

void	ft_line(t_game *game, int w, float dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_f;
	float			d_shift;

	h = (float) HEIGHT / dist;
	src_f = 0.0f;
	d_shift = (float) game->text[game->text_idx].height / h;
	if (h > HEIGHT)
	{
		src_f = 0.5f * (h - HEIGHT) / h * game->text[game->text_idx].height;
		h = HEIGHT;
	}
	src = (unsigned int *) game->text[game->text_idx].addr;
	src += (int)((float) game->text_w * game->text[game->text_idx].width);
	dst = (unsigned int *) game->img.addr + w + (HEIGHT - h) / 2 * WIDTH;
	while (h-- > 0)
	{
		*dst = *(src + ((int)src_f) * game->text[game->text_idx].width);
		dst += WIDTH;
		src_f += d_shift;
	}
}

void	ft_redraw(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	ft_draw_ceiling_and_floor(game);
	ft_ray_casting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img);
}
