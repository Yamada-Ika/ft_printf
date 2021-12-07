/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_upper_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:08:47 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/07 02:27:31 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_upper_x(va_list *ap, size_t write_len)
{
	char	*upper_hex;

	upper_hex = ft_itoa_base(va_arg(*ap, int), "0123456789ABCDEF");
	if (upper_hex == NULL)
		return (ERROR);
	ft_putstr(upper_hex);
	write_len += ft_strlen_s(upper_hex);
	ft_free_s((void **)&upper_hex);
	return (write_len);
}
