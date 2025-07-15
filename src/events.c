/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
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

	delta = 10 * ((*param_factory())->rl_max - (*param_factory())->rl_min) / (*param_factory())->wx;
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
	draw_mandlebrot();
}
