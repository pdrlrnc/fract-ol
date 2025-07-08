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

int	key_handler(int keycode);
int	mouse_handler(int mousecode);
void	write_options(void);
void	parse_args(int argc, char **argv);
void	get_set(char *set);
t_params	**param_factory(void);
void	get_values(char *value1, char type);
void	clean_split(char **split);

#endif
