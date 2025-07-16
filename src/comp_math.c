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

double	compute_magnitude(t_complex point)
{
	double	res;

	res = sqrt((point.rl * point.rl) + (point.im * point.im));
	return (res);
}
