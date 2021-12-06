/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:04:55 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/06 12:18:04 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list *ap, int write_len)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		write_len += (int)ft_strlen_s("(null)");
		return (write_len);
	}
	ft_putstr(s);
	write_len += (int)ft_strlen_s(s);
	return (write_len);
}
