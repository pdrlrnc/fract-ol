/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:18:44 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/17 12:18:49 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_int_values(char *value1, char type)
{
	double	value;

	value = (double) ft_atoi(value1);
	if (type == 'r')
		((*param_factory())->julia_values).rl = value;
	else
		((*param_factory())->julia_values).im = value;
}

void	get_double_values(char *value1, char type)
{
	double	value;
	double	decimal_part;
	char	**split;
	int		hole;
	int		dec;

	value = 0.0;
	split = ft_split(value1, '.');
	hole = ft_atoi(split[0]);
	dec = ft_atoi(split[1]);
	decimal_part = dec;
	dec = ft_nbsize(dec);
	dec += left_zeroes(split[1]);
	while (dec--)
		decimal_part *= 0.1;
	value = abs(hole) + decimal_part;
	if (hole < 0 || *(split[0]) == '-')
		value *= -1;
	if (type == 'r')
		((*param_factory())->julia_values).rl = value;
	else
		((*param_factory())->julia_values).im = value;
	clean_split(split);
}

int	left_zeroes(char *decimal)
{
	int	i;

	i = 0;
	while (*(decimal + i) == '0')
		i++;
	return (i);
}

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

void	write_options(void)
{
	free(*param_factory());
	ft_printf("\033[1;36m");
	ft_printf(" ____  ____    __    ___  ____     _____  __   \n");
	ft_printf("( ___)(  _ \\  /__\\  / __)(_  _)___(  _  )(  )  \n");
	ft_printf(" )__)  )   / /(__)\\( (__   )( (___))(_)(  )(__ \n");
	ft_printf("(__)  (_)\\_)(__)(__)\\___) (__)    (_____)(____)\n");
	ft_printf("               ~ Fract-ol ~                 \n");
	ft_printf("\033[0m");
	ft_printf("               ~ Options: ~                \n");
	ft_printf("-M  --mandelbrot\t\tUse the Mandelbrot set.\n");
	ft_printf("-J  --julia\t\t\tUse the Julia set.");
	ft_printf("NEEDS x and y as in z = x + yi (z is a complex number).\n");
	ft_printf("-W  --window\t\t\tWindow size. NEEDS x and y.");
	ft_printf("X and Y MUST be > 20. Not required.\n\n");
	ft_printf("The set is required. Example:");
	ft_printf(" ./fractol -J 4.3 2.5 --window 600 400\n\n");
	ft_printf("Press ESC at any time of the program exexcution to exit\n\n");
	exit(EXIT_FAILURE);
}
