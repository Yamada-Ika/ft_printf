/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:06:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/14 20:57:33 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	ft_printf_converted_str(const char *format,
	va_list *ap, size_t index, size_t write_len, t_flag_manager *flags)
{
	if (write_len < 0)
		return (write_len);
	if (format[index] == 'c')
		write_len = ft_printf_c(ap, write_len, flags);
	else if (format[index] == 's')
		write_len = ft_printf_s(ap, write_len, flags);
	else if (format[index] == 'p')
		write_len = ft_printf_p(ap, write_len, flags);
	else if (format[index] == 'd' || format[index] == 'i')
		write_len = ft_printf_di(ap, write_len, flags);
	else if (format[index] == 'u')
		write_len = ft_printf_u(ap, write_len, flags);
	else if (format[index] == 'x')
		write_len = ft_printf_lower_x(ap, write_len, flags);
	else if (format[index] == 'X')
		write_len = ft_printf_upper_x(ap, write_len, flags);
	else if (format[index] == '%')
		write_len = ft_printf_percent(write_len, flags);
	return (write_len);
}

static int	ft_printf_helper(const char *format, va_list *ap)
{
	size_t			write_len;
	size_t			i;
	t_flag_manager	flags;

	ft_init_flag_manager(&flags);
	write_len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			i = ft_get_flags(format, i, &flags);
			write_len = ft_printf_converted_str(format, ap, i, write_len, &flags);
			ft_init_flag_manager(&flags);
		}
		else
		{
			ft_putchar(format[i]);
			write_len++;
		}
		if (write_len >= INT_MAX)
			return (ERROR_STATUS);
		i++;
	}
	return ((int)write_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_printf_helper(format, &ap);
	va_end(ap);
	return (ret);
}
