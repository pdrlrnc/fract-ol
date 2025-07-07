/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:23:26 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/25 14:23:45 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_print_dec(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (ft_num_size_nb(nb));
}

int	ft_handle_plain_dec(int nb, t_mdf *mdf)
{
	int	print_length;

	print_length = 0;
	if (nb < 0)
		print_length += ft_print_dec(nb);
	else if (mdf->plus)
		print_length += (ft_print_char('+') + ft_print_dec(nb));
	else if (mdf->space)
		print_length += (ft_print_char(' ') + ft_print_dec(nb));
	else
		print_length += ft_print_dec(nb);
	return (print_length);
}
