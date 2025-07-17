/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:57:59 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/17 11:58:00 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_handler(int mousecode)
{
	if (mousecode == 4)
		zoom_in();
	if (mousecode == 5)
		zoom_out();
	return (0);
}

int	key_handler(int keycode)
{
	if (keycode == 65307)
		cleanup();
	if (keycode == 91)
		(*param_factory())->max_iter++;
	if (keycode == 47)
		(*param_factory())->max_iter--;
	if ((*param_factory())->max_iter <= 0)
		(*param_factory())->max_iter = 1;
	if (keycode == 91 || keycode == 47)
		draw_fractal();
	if (keycode == 65363 || keycode == 65361)
		on_x_axys_key(keycode);
	if (keycode == 65362 || keycode == 65364)
		on_y_axys_key(keycode);
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}
