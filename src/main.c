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
/**	void	**init;
	void	**window;
*/
	parse_args(argc, argv);
/**	init = params_factory('i');
	window = params_factory('w');
	*init = mlx_init();
	if(!*init)
		ft_printf("Fds");
	*window = mlx_new_window(*init, 500, 500, "fractol");
	if (!*window)
		ft_printf("Fds2");
	mlx_key_hook(*window, key_handler, NULL);
	mlx_mouse_hook(*window, mouse_handler, NULL);
	mlx_loop(*init);
*/	exit(EXIT_SUCCESS);
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
		return (0);
	//	mlx_destroy_window(*params_factory('i'), *params_factory('w'));
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}
