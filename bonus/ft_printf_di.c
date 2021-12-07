/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:06:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/07 02:27:11 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_di(va_list *ap, size_t write_len)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	if (num == NULL)
		return (ERROR);
	ft_putstr(num);
	write_len += ft_strlen_s(num);
	ft_free_s((void **)&num);
	return (write_len);
}
