/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:06:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/02 10:28:10 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_non_converted_str(const char *format,
	size_t head, size_t tail, int *write_len)
{
	char	*normal_str;

	if (*write_len < 0)
		return ;
	normal_str = ft_substr(format, head, tail - head);
	if (normal_str == NULL)
	{
		*write_len = -1;
		return ;
	}
	ft_putstr(normal_str);
	*write_len += ft_strlen_s(normal_str);
	ft_free_s((void **)&normal_str);
}

static void	ft_print_converted_str(const char *format,
	va_list *ap, size_t tail, int *write_len)
{
	size_t	i;

	if (*write_len < 0)
		return ;
	i = tail + 1;
	if (format[i] == 'c')
		ft_print_c(ap, write_len);
	else if (format[i] == 's')
		ft_print_s(ap, write_len);
	else if (format[i] == 'p')
		ft_print_p(ap, write_len);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_di(ap, write_len);
	else if (format[i] == 'u')
		ft_print_u(ap, write_len);
	else if (format[i] == 'x')
		ft_print_lower_x(ap, write_len);
	else if (format[i] == 'X')
		ft_print_upper_x(ap, write_len);
	else if (format[i] == '%')
		ft_print_percent(write_len);
}

static int	ft_printf_helper(const char *format, va_list *ap)
{
	int		write_len;
	size_t	tail;
	size_t	head;

	write_len = 0;
	tail = 0;
	head = 0;
	while (format[tail] != '\0')
	{
		if (format[tail] == '%')
		{
			ft_print_non_converted_str(format, head, tail, &write_len);
			ft_print_converted_str(format, ap, tail, &write_len);
			tail += 2;
			head = tail;
		}
		else
			tail++;
	}
	ft_print_non_converted_str(format, head, tail, &write_len);
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
