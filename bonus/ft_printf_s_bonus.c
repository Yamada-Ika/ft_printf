/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:04:55 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/09 02:48:11 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_s(va_list *ap, size_t write_len, t_flag_manager *flags)
{
	char	*str;
	char	*heap_str;
	char	*cutted_off_str;
	size_t	str_len;

	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		write_len += ft_strlen_s("(null)");
		return (write_len);
	}
	heap_str = ft_strdup(str);
	if (heap_str == NULL)
		return (ERROR);
	str_len = ft_strlen_s(heap_str);
	if (write_len + str_len >= INT_MAX)
		return (ERROR);
	cutted_off_str = ft_cut_off_str(heap_str, str_len, flags);
	write_len = ft_print_with_flags(flags, cutted_off_str, write_len);
	return (write_len);
}