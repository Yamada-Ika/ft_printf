/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:07:47 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/09 01:36:55 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_u(va_list *ap, size_t write_len, t_flag_manager *flags)
{
	char	*num;

	num = ft_uitoa(va_arg(*ap, unsigned int));
	if (num == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, num, write_len);
	ft_free_s((void **)&num);
	return (write_len);
}
