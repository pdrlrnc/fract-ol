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
	while (++i < 500)
	{
		curr = add_complex(square_complex(curr), point);
		if (((curr.rl * curr.rl) + (curr.im * curr.im)) > 4)
			return (0);
	}
	return (1);

}

void	draw_mandlebrot(void)
{
	t_pixel pixel;

	pixel.px = 0;
	pixel.py = 0;
	while (pixel.py < (*param_factory())->wy)
	{
		pixel.px = 0;
		while (pixel.px < (*param_factory())->wx)
		{
			if (is_in_mandlebrot(scale_mandlebrot(pixel)))
				my_mlx_pixel_put(pixel.px, pixel.py, 0x00FF0000);
			pixel.px++;
		}
		pixel.py++;
	}
}

t_complex	square_complex(t_complex point)
{
	t_complex	res;

	res.rl = (point.rl * point.rl) - (point.im * point.im);
	res.im = 2 * point.rl * point.im;
	return (res);
}

t_complex	add_complex(t_complex point1, t_complex point2)
{
	t_complex	res;

	res.rl = point1.rl + point2.rl;
	res.im = point1.im + point2.im;
	return (res);
}
