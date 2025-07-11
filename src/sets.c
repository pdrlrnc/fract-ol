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

void	draw_mandlebrot(t_complex point)
{

	int			i;
	t_complex	curr;

	i = 0;
	curr.rl = point.rl;
	curr.im = point.im;
	while (++i < 10000)
	{
		curr = add_complex(square_complex(curr), point);
		if (((curr.rl * curr.rl) + (curr.im * curr.im)) > 4)
		{
			printf("NOT IN MANDLEBROT\n");
			break ;
		}
		printf("it %d: (%f + %fi)\n", i, curr.rl, curr.im);
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
