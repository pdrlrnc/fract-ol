/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:18:27 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/11 15:18:40 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	scale_pixel(t_pixel p)
{
	t_complex	res;
	double	aspect;
	double	real_range;
	double	imag_range;

	real_range = (*param_factory())->rl_max - (*param_factory())->rl_min;
	imag_range = (*param_factory())->im_max - (*param_factory())->im_min;
	aspect = (*param_factory())->wy / (*param_factory())->wx;
	res.rl = (*param_factory())->rl_min + ((double)p.px / (*param_factory())->wx) * real_range;
	res.im = (*param_factory())->im_min + ((double)p.py / (*param_factory())->wy) * imag_range;
	return (res);
}

int	get_colour(int i, t_complex z)
{
	double	mod;
	double	smooth;
	unsigned int	colour;

	mod = i + 1.0 - log(log(sqrt(z.rl * z.rl + z.im * z.im))) / log(2.0);
	smooth = mod / 500;
	if (smooth < 0)
		smooth = 0.0;
	if (smooth > 1)
		smooth = 1.0;
	colour = (unsigned int)(smooth * 0xFFFFFF);
	if (i == 500)
		colour = 0x000000;
	return (colour);
}
