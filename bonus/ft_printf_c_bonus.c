/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 06:26:53 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/10 01:24:52 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_printf_c(va_list *ap, size_t write_len, t_flag_manager *flags)
{
	int	c;

	c = va_arg(*ap, int);
	write_len = ft_print_fill(flags, write_len, c);
	return (write_len);
}
