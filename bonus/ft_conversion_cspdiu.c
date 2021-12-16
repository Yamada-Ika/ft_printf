/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_cspdiu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:11:37 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:42:13 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_printf_c(va_list *ap, size_t write_len, t_flags *flags)
{
	int	c;

	c = va_arg(*ap, int);
	write_len = ft_printf_c_with_flags(flags, write_len, c);
	return (write_len);
}

size_t	ft_printf_s(va_list *ap, size_t write_len, t_flags *flags)
{
	char	*str;
	char	*heap_str;
	char	*cutted_off_str;
	size_t	str_len;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	heap_str = ft_strdup(str);
	if (heap_str == NULL)
		return (ERROR);
	str_len = ft_strlen_s(heap_str);
	if (write_len + str_len >= INT_MAX)
		return (ERROR);
	cutted_off_str = ft_cut_off_str(heap_str, str_len, flags);
	write_len = ft_print_with_flags(flags, &cutted_off_str, write_len);
	ft_free_s((void **)&cutted_off_str);
	return (write_len);
}

size_t	ft_printf_p(va_list *ap, size_t write_len, t_flags *flags)
{
	char	*hex_str;

	hex_str = ft_ultoa_base((unsigned long)va_arg(*ap, void *), "0123456789abcdef");
	if (hex_str == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, &hex_str, write_len);
	ft_free_s((void **)&hex_str);
	return (write_len);
}

size_t	ft_printf_di(va_list *ap, size_t write_len, t_flags *flags)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	if (num == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, &num, write_len);
	ft_free_s((void **)&num);
	return (write_len);
}

size_t	ft_printf_u(va_list *ap, size_t write_len, t_flags *flags)
{
	char	*num;

	num = ft_uitoa(va_arg(*ap, unsigned int));
	if (num == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, &num, write_len);
	ft_free_s((void **)&num);
	return (write_len);
}
