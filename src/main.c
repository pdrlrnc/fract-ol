/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:27:14 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/07 12:27:53 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	parse_args(argc, argv);
	(*param_factory())->init = mlx_init();
	if(!(*param_factory())->init)
		ft_printf("Fds");
	(*param_factory())->window = mlx_new_window((*param_factory())->init , (*param_factory())->wx,  (*param_factory())->wy, "fract-ol");
	if (!(*param_factory())->window)
		ft_printf("Fds2");
	mlx_key_hook((*param_factory())->window, key_handler, NULL);
	mlx_mouse_hook((*param_factory())->window, mouse_handler, NULL);
	mlx_loop((*param_factory())->init);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int mousecode)
{
	if (mousecode)
		return (0);
	return (1);
}

int	key_handler(int keycode)
{
	if (keycode == 65307)
	{
		mlx_destroy_window((*param_factory())->init,(*param_factory())->window);
		free(*param_factory());
	}
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}
