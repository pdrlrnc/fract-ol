/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:32:12 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/15 15:32:15 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	draw_julia(void)
{
	t_pixel	pixel;
	int		step;

	pixel.px = 0;
	pixel.py = 0;
	step = 0x00FFFFFF / 500;
	while (pixel.py < (*param_factory())->wy)
	{
		pixel.px = 0;
		while (pixel.px < (*param_factory())->wx)
		{
			my_mlx_pixel_put(pixel.px, pixel.py, (is_in_julia(scale_mandlebrot(pixel))* step));
			pixel.px++;
		}
		pixel.py++;
	}
	mlx_clear_window((*param_factory())->init, (*param_factory())->window);
	mlx_put_image_to_window((*param_factory())->init, (*param_factory())->window, (*image_factory())->image, 0, 0);
}

int	is_in_julia(t_complex complex)
{
	t_complex	squared;
	t_complex	aux;
	int	i;

	i = 0;
	while (++i < 50000)
	{
		squared.rl = complex.rl * complex.rl;
		squared.im = complex.im * complex.im;
		if (squared.rl + squared.im > 4.0)
			return (i);
		aux.rl = squared.rl - squared.im + (*param_factory())->julia_values.rl;
		aux.im = 2 * complex.rl * complex.im + (*param_factory())->julia_values.im;
		complex.rl = aux.rl;
		complex.im = aux.im;
	}
	return (i);
}
