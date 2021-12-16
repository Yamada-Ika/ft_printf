/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:19:17 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:42:13 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_cut_off_str(char *str, size_t str_len, t_flags *flags)
{
	size_t	i;
	size_t	cut_off_len;

	if (!flags->is_dot)
		return (str);
	if (flags->prec < str_len)
	{
		cut_off_len = str_len - flags->prec;
		i = 0;
		while (i < cut_off_len)
		{
			str[str_len - 1 - i] = '\0';
			i++;
		}
	}
	return (str);
}
