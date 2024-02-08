/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:54:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/08 20:50:59 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialize(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol!");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT); //새로운 이미지 생성 
	//생성된 이미지에 대한 정보 리턴 (사용할 이미지 정보 넘겨서 색상 나타낼 때 필요한 비트수, 이미지 한 줄 저장 시 사용되는 바이트 수, 색상 저장 방식)
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length, &f->endian);
	f->zoom = 1;
	f->min_x = WIDTH / 2;
	f->min_y = HEIGHT / 2;
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