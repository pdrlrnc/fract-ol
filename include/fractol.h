/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:18:01 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/07 12:18:59 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx_int.h"
#include "mlx.h"
#include "libft.h"
#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_params
{
	char	set;
	double	rl;
	double	im;
	double	wx;
	double	wy;
	void	*init;
	void	*window;
}	t_params;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_image;

int	key_handler(int keycode);
int	mouse_handler(int mousecode);
void	write_options(void);
void	parse_args(int argc, char **argv);
void	get_set(char *set);
t_params	**param_factory(void);
void	get_double_values(char *value1, char type);
void	get_int_values(char *value1, char type);
void	clean_split(char **split);
int	check_nb(char *nb);
t_image	**image_factory(void);
void	setup_image(void);
void	my_mlx_pixel_put(int x, int y, int color);

#endif
