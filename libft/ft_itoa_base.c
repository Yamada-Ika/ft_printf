/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:55:56 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/02 10:33:05 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_base_helper(unsigned int u_n, char *base,
	unsigned int radix, size_t digits)
{
	char	*converted_num;

	if (u_n <= radix - 1)
	{
		converted_num = ft_calloc(digits + 1, sizeof(char));
		if (converted_num == NULL)
			return (NULL);
		converted_num[digits - 1] = base[u_n];
		return (converted_num);
	}
	converted_num = ft_itoa_base_helper(u_n / radix, base, radix, digits + 1);
	if (converted_num == NULL)
		return (NULL);
	converted_num[digits - 1] = base[u_n % radix];
	return (converted_num);
}

char	*ft_itoa_base(int n, char *base)
{
	unsigned int	radix;
	unsigned int	u_n;

	if (ft_strcmp(base, "0123456789") == 0)
		return (ft_itoa(n));
	radix = ft_strlen(base);
	u_n = (unsigned int)n;
	return (ft_strrev(ft_itoa_base_helper(u_n, base, radix, 1)));
}
