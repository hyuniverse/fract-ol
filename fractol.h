/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:59:15 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/08 21:58:34 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			type;
	t_complex	julia;
	int			x;
	int			y;
	double		zoom;
	double		min_x;
	double		min_y;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_fractol;

void	my_mlx_pixel_put(t_fractol	*f, int x, int y, int color);
int		exit_hook(void);
int		key_hook(int keycode, t_fractol *f);
void	initialize(t_fractol *f);
void	main_mandelbrot(void);
void	main_julia(double real, double imag);

void	print_man(void);

#endif
