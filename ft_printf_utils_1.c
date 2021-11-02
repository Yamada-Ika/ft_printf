/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:17:23 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/02 10:22:40 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(va_list *ap, int *write_len)
{
	ft_putchar(va_arg(*ap, int));
	*write_len += 1;
}

void	ft_print_s(va_list *ap, int *write_len)
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

void	ft_print_p(va_list *ap, int *write_len)
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

void	ft_print_di(va_list *ap, int *write_len)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	ft_putstr(num);
	*write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
}

void	ft_print_u(va_list *ap, int *write_len)
{
	char	*num;

	num = ft_uitoa(va_arg(*ap, unsigned int));
	ft_putstr(num);
	*write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
}
