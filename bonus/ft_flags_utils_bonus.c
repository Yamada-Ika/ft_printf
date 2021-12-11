/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:21:42 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/12 03:07:29 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_cut_off_str(char *str, size_t str_len, t_flag_manager *flags)
{
	size_t	i;
	size_t	cut_off_len;

	if (flags->is_dot == false)
		return (str);
	if (flags->precision < str_len)
	{
		cut_off_len = str_len - flags->precision;
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
	if (str[0] == '0' && flags->conversion != 'p')
		return (str_len);
	if ((flags->is_sharp && flags->conversion == 'x') || flags->conversion == 'p')
	{
		ft_putstr("0x");
		str_len += 2;
	}
	if (flags->is_sharp && flags->conversion == 'X')
	{
		ft_putstr("0X");
		str_len += 2;
	}
	return (str_len);
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
	return (((flags->is_sharp && flags->conversion == 'x') || \
		(flags->is_sharp && flags->conversion == 'X') || flags->conversion == 'p'));
}

void	ft_calc_fill(t_flag_manager *flags, t_fill_manager *fills, char **str, size_t str_len, size_t num_len)
{
	if (ft_is_print_prefix(flags))
		str_len += 2;
	ft_init_fill_manager(fills);
	if (flags->is_space && ft_isdigit((*str)[0]) && flags->conversion == 'd')
		fills->space_flag_fill++;
	if (flags->is_plus && ft_isdigit((*str)[0]) && flags->conversion == 'd')
		fills->plus_fill++;
	if (flags->is_zero && flags->precision == 0 && !flags->is_minus)
	{
		flags->precision = flags->width;
		flags->width = 0;
	}
	if (flags->conversion == 'd' && (*str)[0] == '-' && flags->is_dot)
		num_len--;
	if (num_len < flags->precision && flags->conversion != 's' && !ft_is_print_prefix(flags))
		fills->zero_fill_num = flags->precision - num_len;
	else if (str_len < flags->precision)
		fills->zero_fill_num = flags->precision - str_len;
	if (ft_is_print_prefix(flags) && flags->width > 0 && flags->is_dot && flags->precision > num_len)
		fills->zero_fill_num = flags->precision - num_len;
	if (flags->conversion == 's' && flags->is_dot)
		fills->zero_fill_num = 0;
	if (str_len < flags->width && flags->width >= flags->precision)
		fills->space_fill_num = flags->width - (fills->zero_fill_num + str_len) - (fills->space_flag_fill + fills->plus_fill);
}

size_t	ft_print_with_fill(t_flag_manager *flags, t_fill_manager *fills, char *str, size_t str_len, size_t num_len)
{
	if (flags->is_minus == false)
		ft_fill_c(fills->space_fill_num, ' ');
	ft_fill_c(fills->minus_fill, '-');
	ft_fill_c(fills->space_flag_fill, ' ');
	ft_fill_c(fills->plus_fill, '+');
	if (flags->conversion != 'd')
		str_len = ft_put_prefix(flags, str, num_len);
	ft_fill_c(fills->zero_fill_num, '0');
	ft_putstr(str);
	if (flags->is_minus == true)
		ft_fill_c(fills->space_fill_num, ' ');
	return (str_len + fills->space_fill_num + fills->zero_fill_num + fills->space_flag_fill + fills->plus_fill + fills->minus_fill);
}

bool	ft_is_zero_precision(t_flag_manager *flags, char *str, size_t str_len)
{
	return (str_len == 1 && str[0] == '0' && flags->is_dot && flags->precision == 0);
}

size_t	ft_print_with_flags(t_flag_manager *flags, char **str, size_t write_len)
{
	size_t	str_len;
	size_t	num_len;
	t_fill_manager	fills;

	str_len = ft_strlen_s(*str);
	num_len = str_len;
	if (ft_is_zero_precision(flags, *str, str_len))
		return (ft_put_prefix(flags, *str, write_len));
	ft_calc_fill(flags, &fills, str, str_len, num_len);
	if (flags->conversion == 'd' && (*str)[0] == '-')
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

size_t	ft_print_fill(t_flag_manager *flags, size_t write_len, int c)
{
	size_t	space_fill;
	size_t	zero_fill;

	space_fill = 0;
	zero_fill = 0;
	if (flags->is_minus == true)
	{
		ft_putchar(c);
		write_len++;
	}
	if (flags->width > 0)
	{
		if (flags->is_zero && !flags->is_minus)
			zero_fill = flags->width - 1;
		else
			space_fill = flags->width - 1;
	}
	if (flags->is_zero && !flags->is_minus)
		ft_fill_c(zero_fill, '0');
	ft_fill_c(space_fill, ' ');
	if (flags->is_zero && flags->is_minus)
		ft_fill_c(zero_fill, '0');
	if (flags->is_minus == false)
	{
		ft_putchar(c);
		write_len++;
	}
	return (write_len + space_fill + zero_fill);
}

void	ft_fill_c(size_t fill_num, char c)
{
	size_t	i;

	i = 0;
	while (i < fill_num)
	{
		ft_putchar(c);
		i++;
	}
}

void	ft_init_flag_manager(t_flag_manager *flags)
{
	flags->is_minus = false;
	flags->is_zero = false;
	flags->is_dot = false;
	flags->is_sharp = false;
	flags->is_space = false;
	flags->is_plus = false;
	flags->conversion = '\0';
	flags->width = 0;
	flags->precision = 0;
}

bool	ft_is_conversion(const char *format, size_t i)
{
	return (format[i] == 'c' || format[i] == 's' || format[i] == 'p' \
		|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
		|| format[i] == 'x' || format[i] == 'X' || format[i] == '%');
}

void	ft_set_conversion(const char *format, size_t i, t_flag_manager *flags)
{
	if (format[i] == 'c')
		flags->conversion = 'c';
	else if (format[i] == 's')
		flags->conversion = 's';
	else if (format[i] == 'p')
		flags->conversion = 'p';
	else if (format[i] == 'd' || format[i] == 'i')
		flags->conversion = 'd';
	else if (format[i] == 'u')
		flags->conversion = 'u';
	else if (format[i] == 'x')
		flags->conversion = 'x';
	else if (format[i] == 'X')
		flags->conversion = 'X';
	else if (format[i] == '%')
		flags->conversion = '%';
}

void	ft_get_flags(const char *format, size_t *i, t_flag_manager *flags)
{
	size_t	init_i;

	init_i = *i;
	while (format[*i] != '\0')
	{
		if (ft_is_conversion(format, *i))
		{
			ft_set_conversion(format, *i, flags);
			return ;
		}
		else if (format[*i] == '-')
			flags->is_minus = true;
		else if (format[*i] == '0' && *i == init_i)
			flags->is_zero = true;
		else if (format[*i] == '.')
			flags->is_dot = true;
		else if (format[*i] == '#')
			flags->is_sharp = true;
		else if (format[*i] == ' ')
			flags->is_space = true;
		else if (format[*i] == '+')
			flags->is_plus = true;
		else if (ft_isdigit(format[*i]) && flags->is_dot == false)
			flags->width = flags->width * 10 + format[*i] - '0';
		else if (ft_isdigit(format[*i]) && flags->is_dot == true)
			flags->precision = flags->precision * 10 + format[*i] - '0';
		(*i)++;
	}
}
