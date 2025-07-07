/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:06:07 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/15 16:08:03 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (*(str + i))
	{
		ft_putchar_fd(*(str + i), 1);
		i++;
	}
	return (i);
}

static int	ft_print_with_dot(char *str, t_mdf *modifiers, int *old_precision)
{
	int	print_length;

	print_length = 0;
	*old_precision = modifiers->precision;
	if (modifiers->minus)
		while (modifiers->precision-- > 0)
			print_length += ft_print_char(*str++);
	while ((modifiers->width-- - *old_precision) > 0)
		print_length += ft_print_char(' ');
	if (!modifiers->minus)
		while ((modifiers->precision-- > 0 && *str))
			print_length += ft_print_char(*str++);
	return (print_length);
}

int	ft_print_str_mod(char *str, t_mdf *modifiers)
{
	int	print_length;
	int	old_precision;

	print_length = 0;
	if (!modifiers->dot)
	{
		print_length += ft_strlen(str);
		if (modifiers->minus)
			ft_print_str(str);
		while (modifiers->width - print_length > 0)
			print_length += ft_print_char(' ');
		if (!modifiers->minus)
			ft_print_str(str);
	}
	else
		print_length += ft_print_with_dot(str, modifiers, &old_precision);
	return (print_length);
}
