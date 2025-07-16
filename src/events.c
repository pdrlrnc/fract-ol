/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:27:47 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/14 12:27:48 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	on_destroy(void *param)
{
	if (!param)
		cleanup();
	exit(EXIT_SUCCESS);
	return (0);
}

void	on_x_axys_key(int keycode)
{
	double	delta;

	delta = 10 * ((*param_factory())->rl_max - (*param_factory())->rl_min)
		/ (*param_factory())->wx;
	if (keycode == 65363)
	{
		(*param_factory())->rl_min -= delta;
		(*param_factory())->rl_max -= delta;
	}
	else
	{
		(*param_factory())->rl_min += delta;
		(*param_factory())->rl_max += delta;
	}
	draw_fractal();
}

void	on_y_axys_key(int keycode)
{
	double	delta;

	delta = 10 * ((*param_factory())->rl_max - (*param_factory())->rl_min)
		/ (*param_factory())->wy;
	if (keycode == 65364)
	{
		(*param_factory())->im_min -= delta;
		(*param_factory())->im_max -= delta;
	}
	else
	{
		(*param_factory())->im_min += delta;
		(*param_factory())->im_max += delta;
	}
	draw_fractal();
}

void	zoom_in(void)
{
	double	real_c;
	double	imag_c;
	double	half_w;
	double	half_h;

	if ((*param_factory())->zoom < 1.0)
		(*param_factory())->zoom = 1.0;
	(*param_factory())->zoom += 0.01;
	if ((*param_factory())->zoom == 0)
		(*param_factory())->zoom = 1;
	real_c = ((*param_factory())->rl_min + (*param_factory())->rl_max) * 0.5;
	imag_c = ((*param_factory())->im_min + (*param_factory())
			->im_max) * 0.5;
	half_w = ((*param_factory())->rl_max - (*param_factory())->rl_min)
		* 0.5 / (*param_factory())->zoom;
	half_h = ((*param_factory())->im_max - (*param_factory())->im_min)
		* 0.5 / (*param_factory())->zoom;
	(*param_factory())->rl_min = real_c - half_w;
	(*param_factory())->rl_max = real_c + half_w;
	(*param_factory())->im_min = imag_c - half_h;
	(*param_factory())->im_max = imag_c + half_h;
	draw_fractal();
}

void	zoom_out(void)
{
	double	real_c;
	double	imag_c;
	double	half_w;
	double	half_h;

	if ((*param_factory())->zoom > 1.0)
		(*param_factory())->zoom = 1.0;
	(*param_factory())->zoom -= 0.01;
	if ((*param_factory())->zoom == 0)
		(*param_factory())->zoom = 1;
	real_c = ((*param_factory())->rl_min + (*param_factory())->rl_max) * 0.5;
	imag_c = ((*param_factory())->im_min + (*param_factory())->im_max) * 0.5;
	half_w = ((*param_factory())->rl_max - (*param_factory())->rl_min) * 0.5
		/ (*param_factory())->zoom;
	half_h = ((*param_factory())->im_max - (*param_factory())->im_min) * 0.5
		/ (*param_factory())->zoom;
	(*param_factory())->rl_min = real_c - half_w;
	(*param_factory())->rl_max = real_c + half_w;
	(*param_factory())->im_min = imag_c - half_h;
	(*param_factory())->im_max = imag_c + half_h;
	draw_fractal();
}
