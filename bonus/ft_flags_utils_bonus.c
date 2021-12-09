/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:21:42 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/09 04:06:10 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_print_di_with_flags(t_flag_manager *flags, char *str, size_t write_len)
{
	size_t	space_fill;
	size_t	plus_fill;

	space_fill = 0;
	plus_fill = 0;
	if (flags->is_space && ft_isdigit(str[0]))
		space_fill++;
	if (flags->is_plus && ft_isdigit(str[0]))
		plus_fill++;
	ft_fill_c(space_fill, ' ');
	ft_fill_c(plus_fill, '+');
	write_len += space_fill + plus_fill;
	return (ft_print_with_flags(flags, str, write_len));
}

bool	ft_is_zero_precision(t_flag_manager *flags, char *str, size_t str_len)
{
	return (str_len == 1 && str[0] == '0' && flags->is_dot && flags->precision == 0);
}

size_t	ft_put_suffix(t_flag_manager *flags, size_t write_len)
{
	if (flags->is_sharp && flags->conversion == 'x' || flags->conversion == 'p')
	{
		ft_putstr("0x");
		write_len += 2;
	}
	if (flags->is_sharp && flags->conversion == 'X')
	{
		ft_putstr("0X");
		write_len += 2;
	}
	return (write_len);
}

size_t	ft_print_with_flags(t_flag_manager *flags, char *str, size_t write_len)
{
	size_t	str_len;
	size_t	num_len;
	size_t	space_fill_num;
	size_t	zero_fill_num;

	str_len = ft_strlen_s(str);
	num_len = str_len;
	if (ft_is_zero_precision(flags, str, str_len))
		return (ft_put_suffix(flags, write_len));
	if (flags->is_sharp && flags->conversion == 'x' || flags->is_sharp && flags->conversion == 'X' || flags->conversion == 'p')
		str_len += 2;
	space_fill_num = 0;
	zero_fill_num = 0;
	if (num_len < flags->precision && flags->conversion != 's')
		zero_fill_num = flags->precision - num_len;
	if (num_len < flags->width && flags->width >= flags->precision)
		space_fill_num = flags->width - (zero_fill_num + str_len);
	ft_fill_c(space_fill_num, ' ');
	ft_put_suffix(flags, write_len);
	ft_fill_c(zero_fill_num, '0');
	ft_putstr(str);
	write_len += str_len + space_fill_num + zero_fill_num;
	return (write_len);
}

size_t	ft_print_fill(t_flag_manager *flags, size_t write_len)
{
	size_t	fill_num;

	fill_num = 0;
	if (flags->width > 0)
		fill_num = flags->width - 1;
	if (flags->is_zero == true)
		ft_fill_c(fill_num, '0');
	else if (flags->is_zero == false)
		ft_fill_c(fill_num, ' ');
	return (fill_num);
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

bool	ft_is_conversion(const char *format, size_t i, t_flag_manager *flags)
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
		if (ft_is_conversion(format, *i, flags))
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
