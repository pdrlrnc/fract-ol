/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:18:29 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/25 12:18:32 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_handle_sign_dec(int nb, t_mdf *modifiers)
{
	int	print_length;

	print_length = 0;
	if (modifiers->plus && nb > 0)
		print_length += ft_print_char('+');
	if (modifiers->space && nb > 0)
		print_length += ft_print_char(' ');
	return (print_length);
}

int	ft_handle_negative(int *nb, int *num_size)
{
	int	print_length;

	print_length = 0;
	if (*nb < 0)
	{
		print_length += ft_print_char('-');
		*nb = *nb * (-1);
		if (num_size != NULL)
			(*num_size)--;
	}
	return (print_length);
}

int	ft_print_p_dec(int max, int i, char c)
{
	int	print_length;

	print_length = 0;
	while (i < max)
	{
		print_length += ft_print_char(c);
		i++;
	}
	return (print_length);
}

int	ft_validate_flags_dec(t_mdf *modifiers)
{
	if (modifiers->zero && modifiers->minus)
		modifiers->valid = 0;
	if (modifiers->plus && modifiers->space)
		modifiers->valid = 0;
	if (modifiers->hashtag)
		modifiers->valid = 0;
	return (modifiers->valid);
}

int	ft_num_size_nb(long nb)
{
	int	size;

	if (nb == 0)
		return (1);
	size = 0;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb != 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}
