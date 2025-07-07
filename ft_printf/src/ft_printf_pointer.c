/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:35:45 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/16 10:35:49 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long long	ptr_address;
	int					nbr_size;

	nbr_size = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ptr_address = (unsigned long long) ptr;
	ft_putstr_fd("0x", 1);
	nbr_size = ft_putnbr_base_fd(ptr_address, "0123456789abcdef", 1);
	return (nbr_size + 2);
}

static int	ft_ptr_address_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_validate_flags_ptr(t_mdf *modifiers)
{
	if (modifiers->zero || modifiers->space || modifiers->plus)
		modifiers->valid = 0;
	if (modifiers->dot || modifiers->precision)
		modifiers->valid = 0;
	return (modifiers->valid);
}

int	ft_print_ptr_mod(void *ptr, t_mdf *modifiers)
{
	unsigned long	ptr_address;
	int				print_length;

	print_length = 0;
	ptr_address = (unsigned long long) ptr;
	print_length += ft_ptr_address_len(ptr_address) + 2;
	if (modifiers->width <= print_length)
		return (ft_print_ptr(ptr));
	if (modifiers->minus)
	{
		ft_print_ptr(ptr);
		while (print_length < modifiers->width)
			print_length += ft_print_char(' ');
	}
	else
	{
		while (print_length < modifiers->width)
			print_length += ft_print_char(' ');
		ft_print_ptr(ptr);
	}
	return (print_length);
}
