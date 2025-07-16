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

typedef struct s_pixel
{
	int	px;
	int	py;
}	t_pixel;

typedef struct s_complex
{
	double	rl;
	double	im;
}	t_complex;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_image;

typedef struct s_params
{
	char	set;
	int	max_iter;
	t_complex	julia_values;
	double	wx;
	double	wy;
	double	zoom;
	double	rl_max;
	double	rl_min;
	double	im_max;
	double	im_min;
	void	*init;
	void	*window;
}	t_params;



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
void	draw_fractal(void);
t_complex	square_complex(t_complex point);
t_complex	add_complex(t_complex point1, t_complex point2);
t_complex	scale_pixel(t_pixel p);
int	is_in_mandlebrot(t_complex point);
void	cleanup(void);
int	on_destroy(void *param);
void	create_hooks(void);
void	on_x_axys_key(int keycode);
void	on_y_axys_key(int keycode);
void	print_params(void);
int	is_in_julia(t_complex complex);
double	compute_magnitude(t_complex point);
void	zoom_in(void);
void	change_iter(int keycode);

#endif
