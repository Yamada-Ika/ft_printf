/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fills_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:33:56 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:54:29 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_printf_c_with_flags(t_flags *flags, size_t write_len, int c)
{
	t_fills	fills;

	ft_init_fills(&fills);
	if (flags->is_minus)
		write_len += ft_fill_c(c, CHAR_NUM);
	if (flags->width > 0)
	{
		if (flags->is_zero && !flags->is_minus)
			fills.zero_fill = flags->width - CHAR_NUM;
		else
			fills.sp_fill = flags->width - CHAR_NUM;
	}
	if (flags->is_zero && !flags->is_minus)
		ft_fill_c('0', fills.zero_fill);
	ft_fill_c(' ', fills.sp_fill);
	if (flags->is_zero && flags->is_minus)
		ft_fill_c('0', fills.zero_fill);
	if (!flags->is_minus)
		write_len += ft_fill_c(c, CHAR_NUM);
	return (write_len + fills.sp_fill + fills.zero_fill);
}

size_t	ft_fill_c(char c, size_t fill_num)
{
	size_t	write_fill_len;

	write_fill_len = 0;
	while (write_fill_len < fill_num)
	{
		ft_putchar(c);
		write_fill_len++;
	}
	return (write_fill_len);
}
