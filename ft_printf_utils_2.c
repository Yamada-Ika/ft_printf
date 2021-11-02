/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:19:41 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/02 10:32:11 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_lower_x(va_list *ap, int *write_len)
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

void	ft_print_upper_x(va_list *ap, int *write_len)
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

void	ft_print_percent(int *write_len)
{
	ft_putchar('%');
	*write_len += 1;
}
