/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:12:17 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/15 15:14:34 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_length;

	va_start(args, str);
	i = 0;
	print_length = 0;
	if (!str)
		return (-1);
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			i++;
			if (*(str + i))
				print_length += ft_print_arguments(args, (char *) str, &i);
			else
				print_length += ft_print_char('%');
		}
		else
			print_length += ft_print_char(*(str + i));
		i++;
	}
	va_end(args);
	return (print_length);
}
