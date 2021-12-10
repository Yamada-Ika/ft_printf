/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:05:27 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/10 17:14:33 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_printf_p(va_list *ap, size_t write_len, t_flag_manager *flags)
{
	char	*hex;

	hex = ft_ultoa_base((unsigned long)va_arg(*ap, void *), "0123456789abcdef");
	if (hex == NULL)
		return (ERROR);
	write_len = ft_print_with_flags(flags, &hex, write_len);
	ft_free_s((void **)&hex);
	return (write_len);
}
