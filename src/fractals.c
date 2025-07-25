/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:33:25 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/08 18:33:26 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	is_in_mandlebrot(t_complex point)
{
	int			i;
	t_complex	curr;

	i = 0;
	curr.rl = point.rl;
	curr.im = point.im;
	while (i < (*param_factory())->max_iter)
	{
		curr = add_complex(square_complex(curr), point);
		if (((curr.rl * curr.rl) + (curr.im * curr.im)) > 4)
			return (get_colour(i));
		i++;
	}
	return (get_colour((*param_factory())->max_iter));
}

int	is_in_julia(t_complex point)
{
	t_complex	z;
	int			i;

	i = 0;
	z = point;
	while (i < (*param_factory())->max_iter)
	{
		z = add_complex(square_complex(z), (*param_factory())->julia_values);
		if ((z.rl * z.rl) + (z.im * z.im) > 2.0)
			return (get_colour(i));
		i++;
	}
	return (get_colour((*param_factory())->max_iter));
}

void	draw_fractal(void)
{
	t_pixel	pixel;

	pixel.px = 0;
	pixel.py = 0;
	while (pixel.py < (*param_factory())->wy)
	{
		pixel.px = 0;
		while (pixel.px < (*param_factory())->wx)
		{
			if ((*param_factory())->set == 'm')
				my_mlx_pixel_put(pixel.px, pixel.py, (
						is_in_mandlebrot(scale_pixel(pixel))));
			else
				my_mlx_pixel_put(pixel.px, pixel.py, (
						is_in_julia(scale_pixel(pixel))));
			pixel.px++;
		}
		pixel.py++;
	}
	mlx_put_image_to_window((*param_factory())->init, (
			*param_factory())->window, (*image_factory())->image, 0, 0);
}
