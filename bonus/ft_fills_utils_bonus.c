/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fills_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:24:19 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:54:29 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_cut_sign(char **num)
{
	size_t		size;
	long long	abs_num;

	size = ft_strlen_s(*num);
	abs_num = ft_abs(atoll(*num));
	ft_free_s((void **)num);
	*num = ft_lltoa(abs_num);
}

size_t	ft_print_with_fill(t_flags *flags, t_fills *fills, char *str, size_t str_len)
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
	return (str_len + fills->sp_fill + fills->zero_fill + fills->sp_flag_fill + fills->plus_fill + fills->minus_fill);
}

void	ft_calc_fill(t_flags *flags, t_fills *fills, char **str, size_t *str_len)
{
	size_t	non_prefix_len;

	ft_init_fills(fills);
	if (flags->conv == 'p')
		non_prefix_len = ft_calc_fill_p_prehelper(flags, str, str_len);
	else if (flags->conv == 'x' || flags->conv == 'X')
		non_prefix_len = ft_calc_fill_x_prehelper(flags, str, str_len);
	else if (flags->conv == 'd')
		non_prefix_len = ft_calc_fill_di_prehelper(flags, fills, str, str_len);
	else if (flags->conv == 'u')
		non_prefix_len = ft_calc_fill_u_prehelper(flags, str, str_len);
	else
		non_prefix_len = *str_len;
	ft_calc_fill_helper(flags, fills, *str_len, non_prefix_len);
}

size_t	ft_print_with_flags(t_flags *flags, char **str, size_t write_len)
{
	size_t	str_len;
	size_t	num_len;
	t_fills	fills;

	str_len = ft_strlen_s(*str);
	num_len = str_len;
	ft_calc_fill(flags, &fills, str, &str_len);
	if (flags->conv == 'd' && (*str)[0] == '-')
	{
		fills.minus_fill++;
		str_len--;
		ft_cut_sign(str);
		if (*str == NULL)
			return (ERROR);
	}
	write_len += ft_print_with_fill(flags, &fills, *str, str_len);
	return (write_len);
}
