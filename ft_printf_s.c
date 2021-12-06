/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:04:55 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/07 02:40:38 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_s(va_list *ap, size_t write_len)
{
	char	*str;
	size_t	str_len;

	str = va_arg(*ap, char *);
	
	if (str == NULL)
	{
		ft_putstr("(null)");
		write_len += ft_strlen_s("(null)");
		return (write_len);
	}
	str_len = ft_strlen_s(str);
	if (str_len > INT_MAX)
		return (ERROR);
	ft_putstr(str);
	write_len += str_len;
	return (write_len);
}
