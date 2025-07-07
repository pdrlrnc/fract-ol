/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:24:18 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/17 11:50:59 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_print_hex(unsigned long long nb, char ccase)
{
	unsigned long long	nb_ull;

	nb_ull = (unsigned long long) nb;
	if (ccase == 'l')
		return (ft_putnbr_base_fd(nb_ull, "0123456789abcdef", 1));
	else
		return (ft_putnbr_base_fd(nb_ull, "0123456789ABCDEF", 1));
}

int	ft_validate_flags_hex(t_mdf *mdf)
{
	if (mdf->space || mdf->plus)
		mdf->valid = 0;
	if (mdf->zero && mdf->minus)
		mdf->valid = 0;
	if (mdf->zero && mdf->dot)
		mdf->valid = 0;
	return (mdf->valid);
}

int	ft_print_hex_mod(unsigned long long nb, char ccase, t_mdf *mdf)
{
	int		p_l;
	char	*base;

	if (mdf->dot && !mdf->precision && mdf->hashtag && !nb)
		return (0);
	if (mdf->dot && !mdf->precision && !mdf->width && !nb)
		return (0);
	if (ccase == 'u')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	p_l = 0;
	if (!mdf->width && !mdf->precision)
	{
		if (mdf->hashtag && nb != 0)
			p_l += ft_print_hasthag_hex(ccase);
		p_l += ft_print_hex(nb, ccase);
	}
	else if (mdf->width)
		return (ft_pr_hex_wdh(nb, ccase, mdf, ft_putnbr_base_fd(nb, base, -1)));
	else
		return (ft_pr_hex_pr(nb, ccase, mdf, ft_putnbr_base_fd(nb, base, -1)));
	return (p_l);
}

int	ft_pr_hex_wdh(unsigned long long nb, char ccase, t_mdf *mdf, int num_len)
{
	int	p_l;

	p_l = 0;
	if (!mdf->precision)
	{
		if (mdf->hashtag && nb != 0)
			num_len += 2;
		if (mdf->hashtag && nb != 0 && mdf->zero)
			p_l += ft_print_hasthag_hex(ccase);
		if (mdf->zero)
			p_l += ft_print_padding_hex(num_len, mdf->width, '0');
		else if (!mdf->minus)
			p_l += ft_print_padding_hex(num_len, mdf->width, ' ');
		if (mdf->hashtag && nb != 0 && !mdf->zero)
			p_l += ft_print_hasthag_hex(ccase);
		p_l += ft_print_hex(nb, ccase);
		if (mdf->minus)
			p_l += ft_print_padding_hex(num_len, mdf->width, ' ');
	}
	else
		return (ft_pr_hex_wdh_pr(nb, ccase, mdf, num_len));
	return (p_l);
}

int	ft_pr_hex_pr(unsigned long long nb, char ccase, t_mdf *mdf, int num_len)
{
	int	p_l;

	p_l = 0;
	if (mdf->hashtag)
		p_l += ft_print_hasthag_hex(ccase);
	p_l += ft_print_padding_hex(num_len, mdf->precision, '0');
	p_l += ft_print_hex(nb, ccase);
	return (p_l);
}
