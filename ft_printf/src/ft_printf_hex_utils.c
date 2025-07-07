/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:04:49 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/25 15:04:51 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_pr_hex_wdh_pr(unsigned long long nb, char ccase, t_mdf *mdf, int num_len)
{
	int	p_l;

	p_l = 0;
	if (mdf->hashtag && nb != 0 && !mdf->minus)
		p_l += ft_print_padding_hex(mdf->precision + 2, mdf->width, ' ');
	else if (!mdf->hashtag && !mdf->minus)
		p_l += ft_print_padding_hex(mdf->precision, mdf->width, ' ');
	if (mdf->hashtag)
		p_l += ft_print_hasthag_hex(ccase);
	p_l += ft_print_padding_hex(num_len, mdf->precision, '0');
	p_l += ft_print_hex(nb, ccase);
	if (mdf->hashtag && nb != 0 && mdf->minus)
		p_l += ft_print_padding_hex(mdf->precision + 2, mdf->width, ' ');
	else if (!mdf->hashtag && mdf->minus)
		p_l += ft_print_padding_hex(mdf->precision, mdf->width, ' ');
	return (p_l);
}

int	ft_print_hasthag_hex(char ccase)
{
	int	p_l;

	p_l = 0;
	if (ccase == 'l')
		p_l += ft_print_str("0x");
	else
		p_l += ft_print_str("0X");
	return (p_l);
}

int	ft_print_padding_hex(int i, int max, char c)
{
	int	p_l;

	p_l = 0;
	while (i++ < max)
		p_l += ft_print_char(c);
	return (p_l);
}
