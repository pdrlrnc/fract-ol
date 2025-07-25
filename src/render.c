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
	double		real_range;
	double		imag_range;
	double		real_center;
	double		imag_center;

	real_center = ((*param_factory())
			->rl_max + (*param_factory())->rl_min) / 2.0;
	imag_center = ((*param_factory())
			->im_max + (*param_factory())->im_min) / 2.0;
	real_range = ((*param_factory())->rl_max - (*param_factory())->rl_min);
	imag_range = real_range * (*param_factory())->wy / (*param_factory())->wx;
	if (real_range == 0)
		real_range = 1;
	if (imag_range == 0)
		imag_range = 1;
	(*param_factory())->rl_min = real_center - real_range / 2.0;
	(*param_factory())->rl_max = real_center + real_range / 2.0;
	(*param_factory())->im_min = imag_center - imag_range / 2.0;
	(*param_factory())->im_max = imag_center + imag_range / 2.0;
	res.rl = (*param_factory())->rl_min + ((double)p
			.px / (*param_factory())->wx) * real_range;
	res.im = (*param_factory())->im_min + ((double)p
			.py / (*param_factory())->wy) * imag_range;
	return (res);
}

int	get_colour(int i)
{
	int	max;
	int	shade;

	max = (*param_factory())->max_iter;
	if (i == 0)
		return (0xFFFFFF);
	if (i >= max)
		return (0x000000);
	shade = (255 * (max - i)) / max;
	return ((shade << 16) | (shade << 8) | shade);
}

void	check_weird_input(char **argv)
{
	if (ft_strlen(argv[2]) == 1 && (*argv[2] == '+' || *argv[2] == '-'))
		write_options();
	if (ft_strlen(argv[3]) == 1 && (*argv[3] == '+' || *argv[3] == '-'))
		write_options();
	if (check_for_overflow(argv[3]) || check_for_overflow(argv[2]))
		write_options();
}
