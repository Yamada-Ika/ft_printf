/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:06:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/06 02:34:55 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_converted_str(const char *format,
	va_list *ap, size_t index, int *write_len)
{
	if (*write_len < 0)
		return ;
	index++;
	if (format[index] == 'c')
		ft_printf_c(ap, write_len);
	else if (format[index] == 's')
		ft_printf_s(ap, write_len);
	else if (format[index] == 'p')
		ft_printf_p(ap, write_len);
	else if (format[index] == 'd' || format[index] == 'i')
		ft_printf_di(ap, write_len);
	else if (format[index] == 'u')
		ft_printf_u(ap, write_len);
	else if (format[index] == 'x')
		ft_printf_lower_x(ap, write_len);
	else if (format[index] == 'X')
		ft_printf_upper_x(ap, write_len);
	else if (format[index] == '%')
		ft_printf_percent(write_len);
}

static int	ft_printf_helper(const char *format, va_list *ap)
{
	int		write_len;
	size_t	i;

	write_len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_printf_converted_str(format, ap, i, &write_len);
			if (write_len == -1)
				return (write_len);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			write_len++;
		}
		i++;
	}
	return (write_len);
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
