/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_upxlwxper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:14:47 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:42:13 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_printf_upper_x(va_list *ap, size_t write_len, t_flag_manager *flags)
{
	char	*upper_hex;

	upper_hex = ft_itoa_base(va_arg(*ap, int), "0123456789ABCDEF");
	if (upper_hex == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, &upper_hex, write_len);
	ft_free_s((void **)&upper_hex);
	return (write_len);
}

size_t	ft_printf_lower_x(va_list *ap, size_t write_len, t_flags *flags)
{
	char	*lower_hex;

	lower_hex = ft_itoa_base(va_arg(*ap, int), "0123456789abcdef");
	if (lower_hex == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, &lower_hex, write_len);
	ft_free_s((void **)&lower_hex);
	return (write_len);
}

size_t	ft_printf_percent(size_t write_len, t_flags *flags)
{
	write_len = ft_printf_c_with_flags(flags, write_len, '%');
	return (write_len);
}
