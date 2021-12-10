/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:06:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/10 17:22:16 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_printf_di(va_list *ap, size_t write_len, t_flag_manager *flags)
{
	char	*num;

	num = ft_itoa(va_arg(*ap, int));
	if (num == NULL)
		return (ERROR);
	// write_len = ft_print_di_with_flags(flags, num, write_len);
	write_len = ft_print_with_flags(flags, &num, write_len);
	// printf("++malloc_size(num) : %zu\n", malloc_size(num));
	ft_free_s((void **)&num);
	// printf("++malloc_size(num) : %zu\n", malloc_size(num));
	return (write_len);
}
