/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_mdf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:45:10 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/23 15:45:56 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

static void	ft_read_flags(char *str, int *old_i, t_mdf *mdf)
{
	while (ft_is_flag(*(str + *old_i)))
	{
		if (*(str + *old_i) == '-')
			mdf->minus = 1;
		else if (*(str + *old_i) == '+')
			mdf->plus = 1;
		else if (*(str + *old_i) == ' ')
			mdf->space = 1;
		else if (*(str + *old_i) == '#')
			mdf->hashtag = 1;
		else if (*(str + *old_i) == '0')
			mdf->zero = 1;
		(*old_i)++;
	}
}

static t_mdf	*ft_read_specifier(char *str, int *old_i, t_mdf *mdf, int *i)
{
	if (ft_is_specifier(*(str + *old_i)))
	{
		mdf->specifier = *(str + *old_i);
		mdf->valid = 1;
		if (ft_validate_mdf_for_specifier(mdf))
			*i = *old_i;
		else
			(*i)--;
	}
	return (mdf);
}

t_mdf	*ft_validate_mdf(char *str, int *i, t_mdf *mdf)
{
	int	old_i;

	*mdf = (t_mdf){0};
	old_i = *i;
	ft_read_flags(str, &old_i, mdf);
	if (ft_isdigit(*(str + old_i)))
	{
		mdf->width = 0;
		while (ft_isdigit(*(str + old_i)))
			mdf->width = mdf->width * 10 + (*(str + old_i++) - '0');
	}
	if (*(str + old_i) == '.')
	{
		old_i++;
		mdf->dot = 1;
		mdf->precision = 0;
		while (ft_isdigit(*(str + old_i)))
			mdf->precision = mdf->precision * 10 + (*(str + old_i++) - '0');
	}
	return (ft_read_specifier(str, &old_i, mdf, i));
}
