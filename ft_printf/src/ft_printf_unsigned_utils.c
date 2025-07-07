/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:43:58 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/25 14:44:01 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_add_p_u(int i, int max, char c)
{
	int	pr_l;

	pr_l = 0;
	while (i++ < max)
		pr_l += ft_print_char(c);
	return (pr_l);
}

int	ft_validate_flags_uns(t_mdf *mdf)
{
	if (mdf->plus || mdf->space || mdf->hashtag)
		mdf->valid = 0;
	if (mdf->dot && mdf->zero)
		mdf->zero = 0;
	return (mdf->valid);
}
