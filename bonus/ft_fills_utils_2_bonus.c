/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fills_utils_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:27:17 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:54:29 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

long long	ft_abs(long long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_swap_sizet(size_t *num_1, size_t *num_2)
{
	size_t	tmp;

	tmp = *num_1;
	*num_1 = *num_2;
	*num_2 = tmp;
}

void	ft_put_prefix(t_flags *flags, char *str)
{
	if (str[0] == '0' && flags->conv != 'p')
		return ;
	if (flags->conv == 'p' || (flags->is_sharp && flags->conv == 'x'))
		ft_putstr("0x");
	if (flags->is_sharp && flags->conv == 'X')
		ft_putstr("0X");
}

void	ft_init_fills(t_fills *fills)
{
	fills->sp_fill = 0;
	fills->zero_fill = 0;
	fills->sp_flag_fill = 0;
	fills->plus_fill = 0;
	fills->minus_fill = 0;
}
