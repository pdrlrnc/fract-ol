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

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include "printf.h"
# include <stdlib.h>
# include <math.h>
# include <limits.h>

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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_params
{
	int			max_iter;
	char		set;
	void		*init;
	void		*window;
	double		wx;
	double		wy;
	double		zoom;
	double		rl_max;
	double		rl_min;
	double		im_max;
	double		im_min;
	t_complex	julia_values;
}	t_params;

int			key_handler(int keycode);
int			mouse_handler(int mousecode);
int			check_nb(char *nb);
int			is_in_mandlebrot(t_complex point);
int			is_in_julia(t_complex complex);
int			get_colour(int i);
int			on_destroy(void *param);
int			check_for_overflow(char *nb);
int			left_zeroes(char *decimal);
void		write_options(void);
void		parse_args(int argc, char **argv);
void		get_set(char *set);
void		get_double_values(char *value1, char type);
void		get_int_values(char *value1, char type);
void		clean_split(char **split);
void		setup_image(void);
void		my_mlx_pixel_put(int x, int y, int color);
void		draw_fractal(void);
void		cleanup(void);
void		create_hooks(void);
void		on_x_axys_key(int keycode);
void		on_y_axys_key(int keycode);
void		check_weird_input(char **argv);
void		zoom_in(void);
void		zoom_out(void);
void		parse_args_cont(int argc, char **argv);
t_image		**image_factory(void);
double		compute_magnitude(t_complex point);
t_params	**param_factory(void);
t_complex	square_complex(t_complex point);
t_complex	add_complex(t_complex point1, t_complex point2);
t_complex	scale_pixel(t_pixel p);

#endif
