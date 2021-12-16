/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:05:54 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/17 01:54:29 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
#include <malloc/malloc.h>

# define ERROR_STATUS -1
# define ERROR SIZE_T_MAX
# define CHAR_NUM 1
# define PREFIX_LEN 2

typedef struct s_flags
{
	bool	is_minus;
	bool	is_zero;
	bool	is_dot;
	bool	is_sharp;
	bool	is_space;
	bool	is_plus;
	char	conv;
	size_t	width;
	size_t	prec;
}	t_flags;

typedef struct s_fills
{
	size_t	sp_fill;
	size_t	zero_fill;
	size_t	sp_flag_fill;
	size_t	plus_fill;
	size_t	minus_fill;
}	t_fills;

int		ft_printf(const char *format, ...);
size_t	ft_printf_c(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_s(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_p(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_di(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_u(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_lower_x(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_upper_x(va_list *ap, size_t write_len, t_flags *flags);
size_t	ft_printf_percent(size_t write_len, t_flags *flags);

size_t	ft_get_flags(const char *format, size_t i, t_flags *flags);
void	ft_init_flags(t_flags *flags);
size_t	ft_printf_c_with_flags(t_flags *flags, size_t write_len, int c);
size_t	ft_fill_c(char c, size_t fill_num);
size_t	ft_print_with_flags(t_flags *flags, char **str, size_t write_len);
size_t	ft_print_di_with_flags(t_flags *flags, char *str, size_t write_len);
char	*ft_cut_off_str(char *str, size_t str_len, t_flags *flags);

#endif
