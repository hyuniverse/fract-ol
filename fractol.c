/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:01:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/15 20:23:36 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid(char *argv)
{
	char	*p;
	int		cnt;

	p = argv;
	cnt = 0;
	if (*p == '-')
		p++;
	while (*p)
	{
		if (*p == '.')
		{
			cnt++;
			if (cnt > 1)
				return (0);
		}
		else if (!ft_isdigit(*p))
			return (0);
		p++;
	}
	return (1);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
	f->pcx = f->cx;
	f->pcy = f->cy;
	f->ppx = f->px;
	f->ppy = f->py;
	f->px = x;
	f->py = y;
	f->cx += (x - f->ppx) / (long double)WIDTH * 4.0 / f->zoom;
	f->cy += (f->ppy - y) / (long double)HEIGHT * 4.0 / f->zoom;
	if (keycode == SCROLL_UP)
		f->zoom *= 0.5;
	else if (keycode == SCROLL_DOWN)
		f->zoom *= 2.0;
	draw(*f);
	return (0);
}

void	render(t_fractol f)
{
	initialize(&f);
	draw(f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, exit_hook, 0);
	mlx_loop(f.mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc == 2 && ft_strncmp(argv[1], "mandel", 6) == 0)
	{
		f.type = 1;
		render(f);
	}
	else if (argc == 4 && (ft_strncmp(argv[1], "julia", 5) == 0) && \
	is_valid(argv[2]) && is_valid(argv[3]))
	{
		f.type = 2;
		f.julia.real = atof(argv[2]);
		f.julia.imag = atof(argv[3]);
		render(f);
	}
	else
		print_man();
	return (0);
}
