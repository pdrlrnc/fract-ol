/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:44:58 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/15 15:16:45 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_validate_flags_char(t_mdf *modifiers)
{
	if (modifiers->zero || modifiers->hashtag || modifiers->space)
		modifiers->valid = 0;
	if (modifiers->plus || modifiers->precision)
		modifiers->valid = 0;
	return (modifiers->valid);
}

int	ft_print_char_mod(char c, t_mdf *modifiers)
{
	int	print_length;

	print_length = 0;
	if (!modifiers->minus)
		print_length += ft_add_padding_char(1, modifiers->width);
	print_length += ft_print_char(c);
	if (modifiers->minus)
		print_length += ft_add_padding_char(1, modifiers->width);
	return (print_length);
}

int	ft_add_padding_char(int i, int max)
{
	int	print_length;

	print_length = 0;
	while (i++ < max)
		print_length += ft_print_char(' ');
	return (print_length);
}
