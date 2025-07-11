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
	setup_image();
	t_complex	point;
	point.rl = -0.026;
	point.im = -0.608;
	draw_mandlebrot(point);
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
		mlx_destroy_image((*param_factory())->init, (*image_factory())->image);
		mlx_destroy_window((*param_factory())->init,(*param_factory())->window);
		free(*param_factory());
	}
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

void	setup_image(void)
{
	(*image_factory())->image = mlx_new_image((*param_factory())->init, 500, 500);
	(*image_factory())->addr = mlx_get_data_addr((*image_factory())->image, &((*image_factory())->bits_per_pixel), &((*image_factory())->line_length), &((*image_factory())->endian));
	my_mlx_pixel_put(5, 5, 0x00FF0000);
	mlx_put_image_to_window((*param_factory())->init, (*param_factory())->window, (*image_factory())->image, 0, 0);
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = (*image_factory())->addr + (int) ((y * (*image_factory())->line_length + x * ((*image_factory())->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}
