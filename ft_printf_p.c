/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:27 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/06 12:18:43 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(va_list *ap, int write_len)
{
	char	*hex;

	hex = ft_ultoa_base((unsigned long)va_arg(*ap, void *), "0123456789abcdef");
	if (hex == NULL)
		return (-1);
	ft_putstr("0x");
	ft_putstr(hex);
	write_len += (int)ft_strlen_s(hex) + 2;
	ft_free_s((void **)&hex);
	return (write_len);
}
