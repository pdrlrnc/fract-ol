/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:10:35 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/19 14:10:38 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

static int	ft_num_len(unsigned int nb)
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

int	ft_print_unsigned(int nb)
{
	unsigned int	nb_ul;

	if (nb > 0)
		nb_ul = nb;
	else
		nb_ul = UINT_MAX + nb + 1;
	ft_putnbr_fd(nb_ul, 1);
	return (ft_num_len(nb_ul));
}

static int	ft_print_uns_pr(unsigned int nb_ul, t_mdf *mdf, int pr_l)
{
	pr_l += ft_add_p_u(ft_num_len(nb_ul), mdf->precision, '0');
	pr_l += ft_print_unsigned(nb_ul);
	return (pr_l);
}

static int	ft_print_uns_mod_width_and_precision(unsigned int nb_ul, t_mdf *mdf)
{
	int	pr_l;
	int	num_len;

	pr_l = 0;
	num_len = ft_num_len(nb_ul);
	if (!mdf->minus && mdf->precision >= num_len)
		pr_l += ft_add_p_u(mdf->precision, mdf->width, ' ');
	if (!mdf->minus && mdf->precision < num_len)
		pr_l += ft_add_p_u(mdf->precision, mdf->width, ' ');
	pr_l += ft_add_p_u(mdf->precision, mdf->width, '0');
	pr_l += ft_print_unsigned(nb_ul);
	if (mdf->minus && mdf->precision >= num_len)
		pr_l += ft_add_p_u(mdf->precision, mdf->width, ' ');
	if (mdf->minus && mdf->precision < num_len)
		pr_l += ft_add_p_u(mdf->precision, mdf->width, ' ');
	return (pr_l);
}

int	ft_print_uns_mod(int nb, t_mdf *mdf)
{
	int				pr_l;
	unsigned int	nb_ul;

	pr_l = 0;
	if (nb > 0)
		nb_ul = nb;
	else
		nb_ul = UINT_MAX + nb + 1;
	if (!mdf->width && !mdf->precision)
		return (ft_print_unsigned(nb_ul));
	else if (mdf->width && !mdf->precision)
	{
		if (mdf->zero)
			pr_l += ft_add_p_u(ft_num_len(nb_ul), mdf->width, '0');
		else if (!mdf->minus)
			pr_l += ft_add_p_u(ft_num_len(nb_ul), mdf->width, ' ');
		pr_l += ft_print_unsigned(nb_ul);
		if (mdf->minus)
			pr_l += ft_add_p_u(ft_num_len(nb_ul), mdf->width, ' ');
	}
	else if (!mdf->width && mdf->precision)
		return (ft_print_uns_pr(nb_ul, mdf, pr_l));
	else
		return (ft_print_uns_mod_width_and_precision(nb_ul, mdf));
	return (pr_l);
}
