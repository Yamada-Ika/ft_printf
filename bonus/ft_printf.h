/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:05:54 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/09 04:06:13 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

# define ERROR_STATUS -1
# define ERROR SIZE_T_MAX

typedef struct s_flag_manager
{
	bool	is_minus;
	bool	is_zero;
	bool	is_dot;
	bool	is_sharp;
	bool	is_space;
	bool	is_plus;
	char	conversion;
	size_t	width;
	size_t	precision;
}	t_flag_manager;

int		ft_printf(const char *format, ...);
size_t	ft_printf_c(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_s(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_p(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_di(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_u(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_lower_x(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_upper_x(va_list *ap, size_t write_len, t_flag_manager *flags);
size_t	ft_printf_percent(size_t write_len, t_flag_manager *flags);

void	ft_get_flags(const char *format, size_t *i, t_flag_manager *flags);
void	ft_init_flag_manager(t_flag_manager *flags);
size_t	ft_print_fill(t_flag_manager *flags, size_t write_len);
void	ft_fill_c(size_t fill_num, char c);
size_t	ft_print_with_flags(t_flag_manager *flags, char *str, size_t write_len);
size_t	ft_print_di_with_flags(t_flag_manager *flags, char *str, size_t write_len);
char	*ft_cut_off_str(char *str, size_t str_len, t_flag_manager *flags);

#endif
