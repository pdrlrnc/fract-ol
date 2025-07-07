/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:47:56 by pedde-so          #+#    #+#             */
/*   Updated: 2025/05/15 16:43:42 by pedde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UINT_MAX 4294967295

typedef struct s_modifiers
{
	int		minus;
	int		zero;
	int		hashtag;
	int		space;
	int		plus;
	int		width;
	int		precision;
	int		dot;
	char	specifier;
	int		valid;
}		t_mdf;

int		ft_printf(const char *str, ...);
int		ft_print_arguments(va_list args, char *str, int *i);
int		ft_use_modifiers(va_list args, t_mdf *modifiers);
t_mdf	*ft_validate_mdf(char *str, int *i, t_mdf *modifiers);
int		ft_validate_mdf_for_specifier(t_mdf *modifiers);
int		ft_is_flag(char c);
int		ft_is_specifier(char c);
int		ft_print_char(char c);
int		ft_validate_flags_char(t_mdf *modifiers);
int		ft_print_char_mod(char c, t_mdf *modifiers);
int		ft_add_padding_char(int i, int max);
int		ft_print_str(char *str);
int		ft_print_str_mod(char *str, t_mdf *modifiers);
int		ft_print_ptr(void *ptr);
int		ft_validate_flags_ptr(t_mdf *modifiers);
int		ft_print_ptr_mod(void *ptr, t_mdf *modifiers);
int		ft_print_dec(int nb);
int		ft_print_dec_mod(int nb, t_mdf *modifiers);
int		ft_validate_flags_dec(t_mdf *modifiers);
int		ft_handle_sign_dec(int nb, t_mdf *modifiers);
int		ft_handle_plain_dec(int nb, t_mdf *mdf);
int		ft_num_size_nb(long nb);
int		ft_handle_negative(int *nb, int *num_size);
int		ft_print_hex(unsigned long long nb, char ccase);
int		ft_pr_hex_pr(unsigned long long nb, char ccase, t_mdf *mdf, int n_l);
int		ft_pr_hex_wdh(unsigned long long nb, char ccase, t_mdf *mdf, int n_l);
int		ft_print_hex_mod(unsigned long long nb, char ccase, t_mdf *modifiers);
int		ft_pr_hex_wdh_pr(unsigned long long nb, char cc, t_mdf *mdf, int n_l);
int		ft_print_hasthag_hex(char ccase);
int		ft_print_padding_hex(int i, int max, char c);
int		ft_validate_flags_hex(t_mdf *modifiers);
int		ft_print_unsigned(int nb);
int		ft_validate_flags_uns(t_mdf *modifiers);
int		ft_print_uns_mod(int nb, t_mdf *modifiers);
int		ft_print_uns_mod_width_pr(unsigned int nb_ul, t_mdf *modifiers);
int		ft_add_p_u(int i, int max, char c);
int		ft_print_p_dec(int max, int i, char c);

#endif
