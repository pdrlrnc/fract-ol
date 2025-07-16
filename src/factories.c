/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factories.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:26:13 by pedde-so          #+#    #+#             */
/*   Updated: 2025/07/08 16:26:18 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_params	**param_factory(void)
{
	static t_params *params;
	
	if (!params)
	{
		params = malloc(sizeof(t_params));
		if (!params)
			exit(EXIT_FAILURE);
		params->wx = 500;
		params->wy = 500;
		params->max_iter = 1;
		params->zoom = 1.1;
	}
	return (&params);
}

t_image	**image_factory(void)
{
	static t_image	*image;

	if (!image)
	{
		image = malloc(sizeof(t_image));
		if (!image)
			exit(EXIT_FAILURE);
	}
	return (&image);
}
