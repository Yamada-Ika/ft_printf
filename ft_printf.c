/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:06:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/01 12:28:31 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_normal_str(const char *format, size_t head, size_t tail, int *write_len)
{
	char	*normal_str;

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

static void ft_print_c(va_list *ap, int *write_len)
{
	ft_putchar(va_arg(*ap, int));
	*write_len += 1;
}

static void ft_print_s(va_list *ap, int *write_len)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		*write_len += (int)ft_strlen_s("(null)");
		return ;
	}
	ft_putstr(s);
	*write_len += (int)ft_strlen_s(s);
}

static void ft_print_di(va_list *ap, int *write_len)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	ft_putstr(num);
	*write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
}

static void ft_print_u(va_list *ap, int *write_len)
{
	char	*num;

	num = ft_uitoa(va_arg(*ap, unsigned int));
	ft_putstr(num);
	*write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
}

static void ft_print_percent(int *write_len)
{
	ft_putchar('%');
	*write_len += 1;
}

static void ft_print_lower_x(va_list *ap, int *write_len)
{
	char	*lower_hex;

	lower_hex = ft_itoa_base(va_arg(*ap, int), "0123456789abcdef");
	if (lower_hex == NULL)
	{
		*write_len = -1;
		return ;
	}
	ft_putstr(lower_hex);
	*write_len += ft_strlen_s(lower_hex);
	ft_free_s((void **)&lower_hex);
}

static void ft_print_upper_x(va_list *ap, int *write_len)
{
	char	*upper_hex;

	upper_hex = ft_itoa_base(va_arg(*ap, int), "0123456789ABCDEF");
	if (upper_hex == NULL)
	{
		*write_len = -1;
		return ;
	}
	ft_putstr(upper_hex);
	*write_len += ft_strlen_s(upper_hex);
	ft_free_s((void **)&upper_hex);
}

static void ft_print_p(va_list *ap, int *write_len)
{
	char	*ll_hex;

	ll_hex = ft_lltoa_base((long long)va_arg(*ap, void *), "0123456789abcdef");
	if (ll_hex == NULL)
	{
		*write_len = -1;
		return ;
	}
	ft_putstr("0x");
	ft_putstr(ll_hex);
	*write_len += ft_strlen_s(ll_hex) + 2;
	ft_free_s((void **)&ll_hex);
}

static void	ft_print_with_conversion_specifier(const char *format, va_list *ap, size_t tail, int *write_len)
{
	size_t	i;

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

static int ft_printf_helper(const char *format, va_list *ap)
{
	int		write_len;
	size_t	tail;
	size_t	head;

	write_len = 0;
	tail = 0;
	head = 0;
	while (1)
	{
		if (format[tail] == '%')
		{
			ft_print_normal_str(format, head, tail, &write_len);
			if (write_len < 0)
				return (-1);
			ft_print_with_conversion_specifier(format, ap, tail, &write_len);
			if (write_len < 0)
				return (-1);
			tail += 2;
			head = tail;
		}
		else if (format[tail] == '\0')
		{
			ft_print_normal_str(format, head, tail, &write_len);
			if (write_len < 0)
				return (-1);
			break ;
		}
		else
			tail++;
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
