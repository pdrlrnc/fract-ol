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

	aspect = (*param_factory())->wy / (*param_factory())->wx;
	res.rl = -2 + ((p.px) * 4) / ((*param_factory())->wx);
	res.im = (-2 * aspect) + ((p.py) * 4) / ((*param_factory())->wy);
	return (res);
}
