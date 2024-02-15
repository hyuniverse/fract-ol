/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:59:18 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/15 20:31:59 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_man(void)
{
	ft_printf("\nFOLLOWINGS ARE REQUIRED INPUTS & EXAMPLES\n\n");
	ft_printf("[MANDELBROT SET]\n");
	ft_printf("required: 'mandel'\n");
	ft_printf("./fractol mandel\n");
	ft_printf("\n[JULIA SET]\n");
	ft_printf("required: 'julia' with two valid complex plane coords.\n");
	ft_printf("./fractol julia -0.70176 -0.3842\n");
}
