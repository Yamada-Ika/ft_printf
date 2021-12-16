/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fills_calc_helper_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:22:09 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:54:29 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_calc_fill_helper(t_flags *flags, t_fills *fills, size_t str_len, size_t non_prefix_len)
{
	if (non_prefix_len < flags->prec && !(flags->conv == 's' && flags->is_dot))
		fills->zero_fill = flags->prec - non_prefix_len;
	if (str_len + fills->zero_fill < flags->width)
		fills->sp_fill = flags->width - (fills->zero_fill + str_len) - (fills->sp_flag_fill + fills->plus_fill);
	if (flags->is_zero && !flags->is_dot && flags->prec == 0)
		ft_swap_sizet(&(fills->zero_fill), &(fills->sp_fill));
}

size_t	ft_calc_fill_p_prehelper(t_flags *flags, char **str, size_t *str_len)
{
	size_t	hex_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	hex_len = *str_len;
	*str_len += PREFIX_LEN;
	return (hex_len);
}

size_t	ft_calc_fill_x_prehelper(t_flags *flags, char **str, size_t *str_len)
{
	size_t	hex_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	hex_len = *str_len;
	if (flags->is_sharp && (*str)[0] != '0')
		*str_len += PREFIX_LEN;
	return (hex_len);
}

size_t	ft_calc_fill_di_prehelper(t_flags *flags, t_fills *fills, char **str, size_t *str_len)
{
	size_t	unsigend_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	if (flags->is_space && (*str)[0] != '-')
		fills->sp_fill++;
	if (flags->is_plus && (*str)[0] != '-')
		fills->plus_fill++;
	unsigend_len = *str_len;
	if ((*str)[0] == '-' && flags->is_dot)
		unsigend_len--;
	return (unsigend_len);
}

size_t	ft_calc_fill_u_prehelper(t_flags *flags, char **str, size_t *str_len)
{
	size_t	num_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	num_len = *str_len;
	return (num_len);
}
