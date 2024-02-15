/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:54:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/15 21:18:34 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol!");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, \
	&f->line_length, &f->endian);
	f->zoom = 1;
	f->px = WIDTH / 2;
	if (f->type == 1)
		f->px += 0.7 * WIDTH / 4;
	f->py = HEIGHT / 2;
	f->cx = 0;
	f->cy = 0;
}

void	my_mlx_pixel_put(t_fractol	*f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
