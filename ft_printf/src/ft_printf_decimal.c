/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:37:38 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/15 16:51:32 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static int	ft_handle_width_no_minus(int nb, t_mdf *mdf, int num_size)
{
	int	prt_len;

	prt_len = 0;
	if (mdf->zero)
	{
		if (nb > 0 && (mdf->plus || mdf->space))
			num_size++;
		prt_len += ft_handle_sign_dec(nb, mdf);
		prt_len += ft_handle_negative(&nb, NULL);
		prt_len += ft_print_p_dec(mdf->width, num_size, '0');
		prt_len += ft_print_dec(nb);
	}
	else
	{
		if ((mdf->plus || mdf->space) && nb > 0)
			num_size++;
		prt_len = ft_print_p_dec(mdf->width, num_size, ' ');
		prt_len += ft_handle_sign_dec(nb, mdf);
		prt_len += ft_print_dec(nb);
	}
	return (prt_len);
}

static int	ft_handle_width_only_dec(int nb, t_mdf *mdf)
{
	int	prt_len;
	int	num_size;

	num_size = ft_num_size_nb(nb);
	prt_len = 0;
	if (mdf->width <= num_size)
		return (mdf->width = 0, ft_print_dec_mod(nb, mdf));
	else if (mdf->minus)
	{
		prt_len += ft_handle_sign_dec(nb, mdf);
		prt_len += ft_print_dec(nb);
		prt_len += ft_print_p_dec(mdf->width, prt_len, ' ');
	}
	else
		return (ft_handle_width_no_minus(nb, mdf, num_size));
	return (prt_len);
}

static int	ft_precision_no_minus(int nb, int prt_len, t_mdf *mdf, int num_size)
{
	if ((mdf->plus && nb > 0) || nb < 0)
		prt_len += ft_print_p_dec(mdf->width, mdf->precision + 1, ' ');
	else
		prt_len += ft_print_p_dec(mdf->width, mdf->precision, ' ');
	if ((mdf->plus && nb > 0))
		prt_len += ft_print_char('+');
	prt_len += ft_handle_negative(&nb, &num_size);
	prt_len += ft_print_p_dec(mdf->precision, num_size, '0');
	prt_len += ft_print_dec(nb);
	return (prt_len);
}

static int	ft_handle_precision(int nb, t_mdf *mdf)
{
	int	prt_len;
	int	num_size;

	num_size = ft_num_size_nb(nb);
	prt_len = 0;
	if (mdf->width <= mdf->precision)
	{
		prt_len += ft_handle_sign_dec(nb, mdf);
		prt_len += ft_handle_negative(&nb, &num_size);
		prt_len += ft_print_p_dec(mdf->precision, num_size, '0');
		prt_len += ft_print_dec(nb);
	}
	else if (mdf->minus)
	{
		prt_len += ft_handle_sign_dec(nb, mdf);
		prt_len += ft_handle_negative(&nb, &num_size);
		prt_len += ft_print_p_dec(mdf->precision, num_size, '0');
		prt_len += ft_print_dec(nb);
		prt_len += ft_print_p_dec(mdf->width, prt_len, ' ');
	}
	else
		return (ft_precision_no_minus(nb, prt_len, mdf, num_size));
	return (prt_len);
}

int	ft_print_dec_mod(int nb, t_mdf *mdf)
{
	int	prt_len;

	if (nb == 0 && mdf->dot && !mdf->precision && !mdf->width)
		return (0);
	if (!ft_validate_flags_dec(mdf))
		return (ft_use_modifiers(NULL, mdf));
	prt_len = 0;
	if (!mdf->width && !mdf->precision)
		return (ft_handle_plain_dec(nb, mdf));
	else if (mdf->width && !mdf->precision)
		return (ft_handle_width_only_dec(nb, mdf));
	else
		return (ft_handle_precision(nb, mdf));
	return (prt_len);
}
