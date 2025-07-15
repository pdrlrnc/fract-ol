/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:32:21 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/15 13:32:24 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void print_params(void)
{
	printf("set       : %c\n",   (*param_factory())->set);
	printf("rl        : %f\n",   (*param_factory())->rl);
	printf("im        : %f\n",   (*param_factory())->im);
	printf("wx        : %f\n",   (*param_factory())->wx);
	printf("wy        : %f\n",   (*param_factory())->wy);
	printf("rl_max    : %f\n",   (*param_factory())->rl_max);
	printf("rl_min    : %f\n",   (*param_factory())->rl_min);
	printf("im_max    : %f\n",   (*param_factory())->im_max);
	printf("im_min    : %f\n",   (*param_factory())->im_min);
	printf("init ptr  : %p\n",   (*param_factory())->init);
	printf("window ptr: %p\n",   (*param_factory())->window);
}
