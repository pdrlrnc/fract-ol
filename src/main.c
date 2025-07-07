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

int	main(void)
{
	void	**init;
	void	**window;
	
	init = params_factory('i');
	window = params_factory('w');
	*init = mlx_init();
	if(!*init)
		ft_printf("Fds");
	*window = mlx_new_window(*init, 500, 500, "Opa");
	if (!*window)
		ft_printf("Fds2");
	mlx_key_hook(*window, key_handler, NULL);
	mlx_loop(*init);
	exit(EXIT_SUCCESS);
}

void	**params_factory(char param)
{
	static void	*init;
	static void	*window;

	if (param == 'i')
		return (&init);
	if (param == 'w')
		return (&window);
	return (NULL);
}

int	key_handler(int keycode)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(*params_factory('i'), *params_factory('w'));
		exit(EXIT_SUCCESS);
	}
	return (0);
}

