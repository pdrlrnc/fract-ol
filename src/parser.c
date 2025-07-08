/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:05:52 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/08 12:05:52 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	parse_args(int argc, char **argv)
{
	if (argc < 4)
		write_options();
	get_set(argv[1]);
	get_values(argv[2], 'r');
	get_values(argv[3], 'i');

}

void	get_set(char *set)
{
	if (ft_strisequal(set, "-J") || ft_strisequal(set, "--julia"))
		(*param_factory())->set = 'j';
	if (ft_strisequal(set, "-M") || ft_strisequal(set, "--mandelbrot"))
		(*param_factory())->set = 'm';
	if (!((*param_factory())->set))
		write_options();
}

void	get_values(char *value1, char type)
{
	double	value;
	int	hole;
	int	dec;
	int	dec_size;
	char	**split;

	value = 0.0;
	split = ft_split(value1, '.');
	hole = ft_atoi(split[0]);
	value += hole;
	dec = ft_atoi(split[1]);
	dec_size = ft_nbsize(dec);
	while (dec_size--)
		value *= 10;
	value += dec;
	dec_size = ft_nbsize(dec);
	while (dec_size--)
		value *= 0.1;
	value = round(value * 100.0) / 100.0;
	if (type == 'r')
		(*param_factory())->rl = value;
	else
		(*param_factory())->im = value;
	clean_split(split);
}

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

t_params	**param_factory(void)
{
	static t_params *params;
	
	if (!params)
		params = malloc(sizeof(t_params));
	if (!params)
		exit(EXIT_FAILURE);
	return (&params);
}

void	write_options(void)
{
	ft_printf("\033[1;36m");
	ft_printf(" ____  ____    __    ___  ____     _____  __   \n");
	ft_printf("( ___)(  _ \\  /__\\  / __)(_  _)___(  _  )(  )  \n");
	ft_printf(" )__)  )   / /(__)\\( (__   )( (___))(_)(  )(__ \n");
	ft_printf("(__)  (_)\\_)(__)(__)\\___) (__)    (_____)(____)\n");
	ft_printf("               ~ Fract-ol ~                 \n");
	ft_printf("\033[0m");
	ft_printf("               ~ Options: ~                \n");
	ft_printf("-J --julia\t\t\tUse the Julia set\n");
	ft_printf("-M --mandelbrot\t\t\tUse the Mandelbrot set\n");
	ft_printf("-W --window\t\t\tWindow size\n\n");
	ft_printf("After passing the set you should pass x and y as in z = x + yi (z is a complex number). The set is required.\n");
	ft_printf("After passing the window you have to pass x and y for the window size. The window is not required.\n\n");
	ft_printf("Example: ./fractol -J 4.3 2.5 --window 600 400\n\n");
	ft_printf("Press ESC at any time of the program exexcution to exit\n\n");
	exit(EXIT_FAILURE);
}
