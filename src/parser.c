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
	if (argc != 2 && argc != 4 && argc != 5 && argc != 7)
		write_options();
	get_set(argv[1]);
	if ((*param_factory())->set == 'm'
		&& argc == 5
		&& (ft_strisequal(argv[2], "-W")
			|| (ft_strisequal(argv[2], "--window")))
		&& check_nb(argv[3]) == 1
		&& check_nb(argv[4]) == 1)
	{
		(*param_factory())->wx = ft_atoi(argv[3]);
		if ((*param_factory())->wx <= 20)
			write_options();
		(*param_factory())->wy = ft_atoi(argv[4]);
		if ((*param_factory())->wy <= 20)
			write_options();
		return ;
	}
	if ((*param_factory())->set == 'm' && argc == 2)
		return ;
	if ((*param_factory())->set == 'm')
		write_options();
	parse_args_cont(argc, argv);
}

void	parse_args_cont(int argc, char **argv)
{
	if ((*param_factory())->set == 'j' && argc == 2)
		write_options();
	if (check_nb(argv[2]) == 2)
		get_double_values(argv[2], 'r');
	else
		get_int_values(argv[2], 'r');
	if (check_nb(argv[3]) == 2)
		get_double_values(argv[3], 'i');
	else
		get_int_values(argv[3], 'i');
	if (argc == 7
		&& check_nb(argv[5]) == 1
		&& check_nb(argv[6]) == 1
		&& (ft_strisequal(argv[4], "-W") || ft_strisequal(argv[4], "--window")))
	{
		(*param_factory())->wx = ft_atoi(argv[5]);
		if ((*param_factory())->wx <= 20)
			write_options();
		(*param_factory())->wy = ft_atoi(argv[6]);
		if ((*param_factory())->wy <= 20)
			write_options();
		return ;
	}
}

int	check_nb(char *nb)
{
	int	i;

	i = 0;
	while (*(nb + i) && *(nb + i) == ' ')
		i++;
	if (*(nb + i) && (*(nb + i) == '-' || *(nb + i) == '+'))
		i++;
	while (*(nb + i) && *(nb + i) >= '0' && *(nb + i) <= '9')
		i++;
	if (!*(nb + i))
		return (1);
	if (*(nb + i) == '.')
		i++;
	if (!*(nb + i))
		write_options();
	while (*(nb + i) && *(nb + i) >= '0' && *(nb + i) <= '9')
		i++;
	if (!*(nb + i))
		return (2);
	write_options();
	return (-1);
}

void	get_set(char *set)
{
	if (ft_strisequal(set, "-J") || ft_strisequal(set, "--julia"))
		(*param_factory())->set = 'j';
	if (ft_strisequal(set, "-M") || ft_strisequal(set, "--mandelbrot"))
		(*param_factory())->set = 'm';
	(*param_factory())->rl_min = -2;
	(*param_factory())->rl_max = 2;
	(*param_factory())->im_min = -2;
	(*param_factory())->im_max = 2;
	if (!((*param_factory())->set))
		write_options();
}
