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
	if (!(*param_factory())->init)
	{
		free((*param_factory()));
		exit(EXIT_FAILURE);
	}
	(*param_factory())->window = mlx_new_window((*param_factory())
			->init, (*param_factory())->wx, (*param_factory())->wy, "fract-ol");
	if (!(*param_factory())->window)
	{
		free((*param_factory())->init);
		free(*param_factory());
		exit(EXIT_FAILURE);
	}
	create_hooks();
	setup_image();
	mlx_loop((*param_factory())->init);
	exit(EXIT_SUCCESS);
}

void	create_hooks(void)
{
	mlx_hook((*param_factory())
		->window, DestroyNotify, (1L << 17), on_destroy, NULL);
	mlx_key_hook((*param_factory())->window, key_handler, NULL);
	mlx_mouse_hook((*param_factory())->window, mouse_handler, NULL);
}

void	cleanup(void)
{
	mlx_destroy_image((*param_factory())->init, (*image_factory())->image);
	mlx_destroy_window((*param_factory())->init, (*param_factory())->window);
	mlx_destroy_display((*param_factory())->init);
	free((*param_factory())->init);
	free(*param_factory());
	free(*image_factory());
	exit(EXIT_SUCCESS);
}

void	setup_image(void)
{
	(*image_factory())->image = mlx_new_image((*param_factory())
			->init, (*param_factory())->wx, (*param_factory())->wy);
	if (!(*image_factory())->image)
	{
		mlx_destroy_window((*param_factory())->init, (*param_factory())
			->window);
		mlx_destroy_display((*param_factory())->init);
		free((*param_factory())->init);
		free(*param_factory());
		free(*image_factory());
		exit(EXIT_FAILURE);
	}
	(*image_factory())->addr = mlx_get_data_addr((*image_factory())
			->image, &((*image_factory())->bits_per_pixel), &((*image_factory())
				->line_length), &((*image_factory())->endian));
	if (!(*image_factory())->addr)
	{
		cleanup();
		exit(EXIT_FAILURE);
	}
	draw_fractal();
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = (*image_factory())->addr + (int)((y * (*image_factory())
				->line_length + x * ((*image_factory())->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}
