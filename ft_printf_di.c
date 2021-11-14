/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:06:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/14 14:07:11 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_di(va_list *ap, int *write_len)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	ft_putstr(num);
	*write_len += (int)ft_strlen_s(num);
	ft_free_s((void **)&num);
}