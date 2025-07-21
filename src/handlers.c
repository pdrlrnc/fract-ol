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
	if (keycode == XK_Escape)
		cleanup();
	if (keycode == XK_m)
		(*param_factory())->max_iter++;
	if (keycode == XK_l)
		(*param_factory())->max_iter--;
	if ((*param_factory())->max_iter <= 0)
		(*param_factory())->max_iter = 1;
	if (keycode == XK_m || keycode == XK_l)
		draw_fractal();
	if (keycode == XK_Left || keycode == XK_Right)
		on_x_axys_key(keycode);
	if (keycode == XK_Up || keycode == XK_Down)
		on_y_axys_key(keycode);
	return (0);
}
