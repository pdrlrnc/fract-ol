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

	res.rl = -2 + ((p.px) * 4) / ((*param_factory())->wx);
	res.im = -1 + ((p.py) * 2) / ((*param_factory())->wy);
	return (res);
}
