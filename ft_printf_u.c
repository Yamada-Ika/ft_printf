/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:07:47 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/14 15:31:50 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(va_list *ap, int *write_len)
{
	char	*num;

	num = ft_uitoa(va_arg(*ap, unsigned int));
	ft_putstr(num);
	*write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
}
