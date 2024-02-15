/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:59:15 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/15 19:25:26 by sehyupar         ###   ########.fr       */
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
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	long double	real;
	long double	imag;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			type;
	t_complex	julia;
	int			px;
	int			py;
	int			ppx;
	int			ppy;
	long double	cx;
	long double	cy;
	long double	pcx;
	long double	pcy;
	long double	zoom;
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
void	draw(t_fractol f);
void	print_man(void);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);

#endif
