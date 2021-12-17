/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_flags_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:24:19 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 16:49:33 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_print_with_fill(t_flags *flags, t_fills *fills, char *str)
{
	if (!flags->is_minus)
		ft_fill_c(' ', fills->sp_fill);
	ft_fill_c('-', fills->minus_fill);
	ft_fill_c(' ', fills->sp_flag_fill);
	ft_fill_c('+', fills->plus_fill);
	ft_put_prefix(flags, str);
	ft_fill_c('0', fills->zero_fill);
	ft_putstr(str);
	if (flags->is_minus)
		ft_fill_c(' ', fills->sp_fill);
	return (fills->sp_fill + fills->zero_fill + fills->sp_flag_fill \
		+ fills->plus_fill + fills->minus_fill);
}

void	ft_calc_fill(t_flags *flags, t_fills *fills, char **str, \
	size_t *str_len)
{
	size_t	non_prefix_len;

	ft_init_fills(fills);
	if (flags->conv == 'p')
		non_prefix_len = ft_calc_fill_p_helper(flags, str, str_len);
	else if (flags->conv == 'x' || flags->conv == 'X')
		non_prefix_len = ft_calc_fill_x_helper(flags, str, str_len);
	else if (flags->conv == 'd')
		non_prefix_len = ft_calc_fill_di_helper(flags, fills, str, str_len);
	else if (flags->conv == 'u')
		non_prefix_len = ft_calc_fill_u_helper(flags, str, str_len);
	else
		non_prefix_len = *str_len;
	ft_calc_fill_helper(flags, fills, *str_len, non_prefix_len);
	if (flags->conv == 'd' && (*str)[0] == '-')
	{
		fills->minus_fill++;
		(*str_len)--;
		ft_cut_sign(str);
	}
}

bool	ft_is_big_string(t_fills *fills, size_t write_len, size_t str_len)
{
	return ((write_len + str_len + fills->sp_fill + fills->zero_fill \
		+ fills->sp_flag_fill + fills->plus_fill + fills->minus_fill) \
		>= INT_MAX);
}

size_t	ft_print_with_flags(t_flags *flags, char **str, size_t write_len)
{
	size_t	str_len;
	t_fills	fills;

	if (flags->conv == 's')
		ft_cut_off_str(*str, flags);
	str_len = ft_strlen_s(*str);
	ft_calc_fill(flags, &fills, str, &str_len);
	if (*str == NULL)
		return (ERROR);
	if (ft_is_big_string(&fills, write_len, str_len))
		return (ERROR);
	write_len += str_len + ft_print_with_fill(flags, &fills, *str);
	return (write_len);
}
