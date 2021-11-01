/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 00:45:29 by iyamada           #+#    #+#             */
/*   Updated: 2021/10/31 00:46:41 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_lltoa_base_helper(unsigned long long ull_n, char *base, unsigned int radix, size_t digits)
{
	char	*converted_num;

	if (ull_n <= radix - 1)
	{
		converted_num = ft_calloc(digits + 1, sizeof(char));
		if (converted_num == NULL)
			return (NULL);
		converted_num[digits - 1] = base[ull_n];
		return (converted_num);
	}
	converted_num = ft_lltoa_base_helper(ull_n / radix, base, radix, digits + 1);
	if (converted_num == NULL)
		return (NULL);
	converted_num[digits - 1] = base[ull_n % radix];
	return (converted_num);
}

char *ft_lltoa_base(long long n, char *base)
{
	unsigned int		radix;
	unsigned long long	ull_n;

	if (ft_strcmp(base, "0123456789") == 0)
		return (ft_lltoa(n));
	radix = ft_strlen(base);
	ull_n = (unsigned long long)n;
	return (ft_strrev(ft_lltoa_base_helper(ull_n, base, radix, 1)));
}
