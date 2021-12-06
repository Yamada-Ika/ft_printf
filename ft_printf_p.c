/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:27 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/07 02:27:19 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_p(va_list *ap, size_t write_len)
{
	char	*hex;

	hex = ft_ultoa_base((unsigned long)va_arg(*ap, void *), "0123456789abcdef");
	if (hex == NULL)
		return (ERROR);
	ft_putstr("0x");
	ft_putstr(hex);
	write_len += ft_strlen_s(hex) + 2UL;
	ft_free_s((void **)&hex);
	return (write_len);
}
