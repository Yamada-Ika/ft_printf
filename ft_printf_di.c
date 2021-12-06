/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:06:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/06 12:14:20 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_di(va_list *ap, int write_len)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	if (num == NULL)
		return (-1);
	ft_putstr(num);
	write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
	return (write_len);
}
