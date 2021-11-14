/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:27 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/14 14:19:46 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(va_list *ap, int *write_len)
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
