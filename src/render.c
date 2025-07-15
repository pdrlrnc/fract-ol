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

t_complex	scale_mandlebrot(t_pixel p)
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
