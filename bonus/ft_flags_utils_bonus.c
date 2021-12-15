/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:21:42 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/15 16:50:00 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_cut_off_str(char *str, size_t str_len, t_flag_manager *flags)
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

size_t	ft_put_prefix(t_flag_manager *flags, char *str, size_t str_len)
{
	if (str[0] == '0' && flags->conv != 'p')
		return (str_len);
	if (flags->conv == 'p' || (flags->is_sharp && flags->conv == 'x'))
		ft_putstr("0x");
	if (flags->is_sharp && flags->conv == 'X')
		ft_putstr("0X");
	return (str_len + PREFIX_LEN);
}

long long	ft_abs(long long n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_cut_sign(char **num)
{
	size_t		size;
	long long	abs_num;

	size = ft_strlen_s(*num);
	abs_num = ft_abs(atoll(*num));
	ft_free_s((void **)num);
	*num = ft_lltoa(abs_num);
}

void	ft_init_fill_manager(t_fill_manager *fills)
{
	fills->space_fill_num = 0;
	fills->zero_fill_num = 0;
	fills->space_flag_fill = 0;
	fills->plus_fill = 0;
	fills->minus_fill = 0;
}

bool	ft_is_print_prefix(t_flag_manager *flags)
{
	return (((flags->is_sharp && flags->conv == 'x') || \
		(flags->is_sharp && flags->conv == 'X') || flags->conv == 'p'));
}

void	ft_swap_sizet(size_t *num_1, size_t *num_2)
{
	size_t	tmp;

	tmp = *num_1;
	*num_1 = *num_2;
	*num_2 = tmp;
}

void	ft_calc_fill_helper(t_flag_manager *flags, t_fill_manager *fills, size_t str_len, size_t non_prefix_len)
{
	if (non_prefix_len < flags->prec && !(flags->conv == 's' && flags->is_dot))
		fills->zero_fill_num = flags->prec - non_prefix_len;
	if (str_len + fills->zero_fill_num < flags->width)
		fills->space_fill_num = flags->width - (fills->zero_fill_num + str_len) - (fills->space_flag_fill + fills->plus_fill);
	if (flags->is_zero && !flags->is_dot && flags->prec == 0)
		ft_swap_sizet(&(fills->zero_fill_num), &(fills->space_fill_num));
}

size_t	ft_calc_fill_p_prehelper(t_flag_manager *flags, t_fill_manager *fills, char **str, size_t *str_len)
{
	size_t	hex_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	hex_len = *str_len;
	*str_len += PREFIX_LEN;
	return (hex_len);
}

size_t	ft_calc_fill_x_prehelper(t_flag_manager *flags, t_fill_manager *fills, char **str, size_t *str_len)
{
	size_t	hex_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	hex_len = *str_len;
	if (flags->is_sharp && (*str)[0] != '0')
		*str_len += PREFIX_LEN;
	return (hex_len);
}

size_t	ft_calc_fill_di_prehelper(t_flag_manager *flags, t_fill_manager *fills, char **str, size_t *str_len)
{
	size_t	unsigend_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	if (flags->is_space && (*str)[0] != '-')
		fills->space_fill_num++;
	if (flags->is_plus && (*str)[0] != '-')
		fills->plus_fill++;
	unsigend_len = *str_len;
	if ((*str)[0] == '-' && flags->is_dot)
		unsigend_len--;
	return (unsigend_len);
}

size_t	ft_calc_fill_u_prehelper(t_flag_manager *flags, t_fill_manager *fills, char **str, size_t *str_len)
{
	size_t	num_len;

	if ((*str)[0] == '0' && flags->is_dot && flags->prec == 0)
	{
		(*str_len)--;
		(*str)[0] = '\0';
	}
	num_len = *str_len;
	return (num_len);
}

void	ft_calc_fill(t_flag_manager *flags, t_fill_manager *fills, char **str, size_t *str_len)
{
	size_t	non_prefix_len;

	ft_init_fill_manager(fills);
	if (flags->conv == 'p')
		non_prefix_len = ft_calc_fill_p_prehelper(flags, fills, str, str_len);
	else if (flags->conv == 'x' || flags->conv == 'X')
		non_prefix_len = ft_calc_fill_x_prehelper(flags, fills, str, str_len);
	else if (flags->conv == 'd')
		non_prefix_len = ft_calc_fill_di_prehelper(flags, fills, str, str_len);
	else if (flags->conv == 'u')
		non_prefix_len = ft_calc_fill_u_prehelper(flags, fills, str, str_len);
	else if (flags->conv == 's')
		non_prefix_len = *str_len;
	ft_calc_fill_helper(flags, fills, *str_len, non_prefix_len);
}

size_t	ft_print_with_fill(t_flag_manager *flags, t_fill_manager *fills, char *str, size_t str_len, size_t num_len)
{
	if (!flags->is_minus)
		ft_fill_c(' ', fills->space_fill_num);
	ft_fill_c('-', fills->minus_fill);
	ft_fill_c(' ', fills->space_flag_fill);
	ft_fill_c('+', fills->plus_fill);
	ft_put_prefix(flags, str, str_len);
	ft_fill_c('0', fills->zero_fill_num);
	ft_putstr(str);
	if (flags->is_minus)
		ft_fill_c(' ', fills->space_fill_num);
	return (str_len + fills->space_fill_num + fills->zero_fill_num + fills->space_flag_fill + fills->plus_fill + fills->minus_fill);
}

size_t	ft_print_with_flags(t_flag_manager *flags, char **str, size_t write_len)
{
	size_t			str_len;
	size_t			num_len;
	t_fill_manager	fills;

	str_len = ft_strlen_s(*str);
	num_len = str_len;
	ft_calc_fill(flags, &fills, str, &str_len);
	if (flags->conv == 'd' && (*str)[0] == '-')
	{
		fills.minus_fill++;
		str_len--;
		ft_cut_sign(str);
		if (*str == NULL)
			return (ERROR);
	}
	write_len += ft_print_with_fill(flags, &fills, *str, str_len, num_len);
	return (write_len);
}

size_t	ft_printf_c_with_flags(t_flag_manager *flags, size_t write_len, int c)
{
	t_fill_manager	fills;

	ft_init_fill_manager(&fills);
	if (flags->is_minus)
		write_len += ft_fill_c(c, CHAR_NUM);
	if (flags->width > 0)
	{
		if (flags->is_zero && !flags->is_minus)
			fills.zero_fill_num = flags->width - CHAR_NUM;
		else
			fills.space_fill_num = flags->width - CHAR_NUM;
	}
	if (flags->is_zero && !flags->is_minus)
		ft_fill_c('0', fills.zero_fill_num);
	ft_fill_c(' ', fills.space_fill_num);
	if (flags->is_zero && flags->is_minus)
		ft_fill_c('0', fills.zero_fill_num);
	if (!flags->is_minus)
		write_len += ft_fill_c(c, CHAR_NUM);
	return (write_len + fills.space_fill_num + fills.zero_fill_num);
}

size_t	ft_fill_c(char c, size_t fill_num)
{
	size_t	write_fill_len;

	write_fill_len = 0;
	while (write_fill_len < fill_num)
	{
		ft_putchar(c);
		write_fill_len++;
	}
	return (write_fill_len);
}

void	ft_init_flag_manager(t_flag_manager *flags)
{
	flags->is_minus = false;
	flags->is_zero = false;
	flags->is_dot = false;
	flags->is_sharp = false;
	flags->is_space = false;
	flags->is_plus = false;
	flags->conv = '\0';
	flags->width = 0;
	flags->prec = 0;
}

void	ft_set_conversion(const char *format, size_t i, t_flag_manager *flags)
{
	if (format[i] == 'c')
		flags->conv = 'c';
	else if (format[i] == 's')
		flags->conv = 's';
	else if (format[i] == 'p')
		flags->conv = 'p';
	else if (format[i] == 'd' || format[i] == 'i')
		flags->conv = 'd';
	else if (format[i] == 'u')
		flags->conv = 'u';
	else if (format[i] == 'x')
		flags->conv = 'x';
	else if (format[i] == 'X')
		flags->conv = 'X';
	else if (format[i] == '%')
		flags->conv = '%';
}

bool	ft_is_numeric_conversion(t_flag_manager *flags)
{
	return (flags->conv == 'd' || flags->conv == 'i' || flags->conv == 'u' \
		|| flags->conv == 'x' || flags->conv == 'X');
}

void	ft_consider_flags_priority(t_flag_manager *flags)
{
	if (ft_is_numeric_conversion(flags) && flags->is_dot && flags->is_zero)
		flags->is_zero = false;
	if (flags->is_minus && flags->is_zero)
		flags->is_zero = false;
	if (flags->is_plus && flags->is_space)
		flags->is_space = false;
}

bool	ft_is_conversion(const char *format, size_t i, t_flag_manager *flags)
{
	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' \
		|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
		|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
	{
		ft_set_conversion(format, i, flags);
		ft_consider_flags_priority(flags);
		return (true);
	}
	return (false);

}

size_t	ft_get_flags(const char *format, size_t index, t_flag_manager *flags)
{
	size_t	init_index;

	init_index = index;
	while (format[index] != '\0' && !ft_is_conversion(format, index, flags))
	{
		if (format[index] == '-')
			flags->is_minus = true;
		else if (format[index] == '0' && i == init_i)
			flags->is_zero = true;
		else if (format[index] == '.')
			flags->is_dot = true;
		else if (format[index] == '#')
			flags->is_sharp = true;
		else if (format[index] == ' ')
			flags->is_space = true;
		else if (format[index] == '+')
			flags->is_plus = true;
		else if (ft_isdigit(format[index]) && !flags->is_dot)
			flags->width = flags->width * 10 + format[index] - '0';
		else if (ft_isdigit(format[index]) && flags->is_dot)
			flags->prec = flags->prec * 10 + format[index] - '0';
		index++;
	}
	return (index);
}
