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
	create_hooks();
	setup_image();
	mlx_loop((*param_factory())->init);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int mousecode)
{
	if (mousecode == 4)
		zoom_in();
	if (mousecode == 5)
		zoom_out();
	return (0);
}

void	create_hooks(void)
{
	mlx_hook((*param_factory())->window, DestroyNotify, (1L<<17), on_destroy, NULL);
	mlx_key_hook((*param_factory())->window, key_handler, NULL);
	mlx_mouse_hook((*param_factory())->window, mouse_handler, NULL);
}

void	cleanup(void)
{
	mlx_destroy_image((*param_factory())->init, (*image_factory())->image);
	mlx_destroy_window((*param_factory())->init,(*param_factory())->window);
	mlx_destroy_display((*param_factory())->init);
	free((*param_factory())->init);
	free(*param_factory());
	free(*image_factory());
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode)
{
	if (keycode == 65307)
		cleanup();
	if (keycode == 91 || keycode == 93)
		change_iter(keycode);
	if (keycode == 65363 || keycode == 65361)
		on_x_axys_key(keycode);
	if (keycode == 65362 || keycode == 65364)
		on_y_axys_key(keycode);
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

void	setup_image(void)
{
	(*image_factory())->image = mlx_new_image((*param_factory())->init, (*param_factory())->wx, (*param_factory())->wy);
	(*image_factory())->addr = mlx_get_data_addr((*image_factory())->image, &((*image_factory())->bits_per_pixel), &((*image_factory())->line_length), &((*image_factory())->endian));
	draw_fractal();
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = (*image_factory())->addr + (int) ((y * (*image_factory())->line_length + x * ((*image_factory())->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}
