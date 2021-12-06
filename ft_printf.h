/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:05:54 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/06 12:17:41 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_printf_c(va_list *ap, int write_len);
int	ft_printf_s(va_list *ap, int write_len);
int	ft_printf_p(va_list *ap, int write_len);
int	ft_printf_di(va_list *ap, int write_len);
int	ft_printf_u(va_list *ap, int write_len);
int	ft_printf_lower_x(va_list *ap, int write_len);
int	ft_printf_upper_x(va_list *ap, int write_len);
int	ft_printf_percent(int write_len);

#endif
