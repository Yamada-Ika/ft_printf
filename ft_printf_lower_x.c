/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lower_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:08:19 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/06 12:19:05 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lower_x(va_list *ap, int write_len)
{
	char	*lower_hex;

	lower_hex = ft_itoa_base(va_arg(*ap, int), "0123456789abcdef");
	if (lower_hex == NULL)
		return (-1);
	ft_putstr(lower_hex);
	write_len += (int)ft_strlen_s(lower_hex);
	ft_free_s((void **)&lower_hex);
	return (write_len);
}
