/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:05:54 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/02 10:31:45 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_print_c(va_list *ap, int *write_len);
void	ft_print_s(va_list *ap, int *write_len);
void	ft_print_p(va_list *ap, int *write_len);
void	ft_print_di(va_list *ap, int *write_len);
void	ft_print_u(va_list *ap, int *write_len);
void	ft_print_lower_x(va_list *ap, int *write_len);
void	ft_print_upper_x(va_list *ap, int *write_len);
void	ft_print_percent(int *write_len);

#endif
