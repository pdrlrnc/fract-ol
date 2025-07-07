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
#include "printf.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_params
{
	void	*init;
	void	*window;

}	t_params;

int	key_handler(int keycode);
void	**params_factory(char param);

#endif
