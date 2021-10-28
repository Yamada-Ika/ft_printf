/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:06:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/10/28 23:59:15 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	ft_putstr_fd(char *c, int fd)
{
	size_t	c_len;
	size_t	prev_write_len;
	char	*tmp_c;

	if (c == NULL)
		return ;
	tmp_c = c;
	c_len = ft_strlen(tmp_c);
	prev_write_len = c_len % INT_MAX;
	write(fd, tmp_c, prev_write_len);
	tmp_c += prev_write_len;
	c_len /= INT_MAX;
	while (c_len-- > 0)
	{
		write(fd, tmp_c, INT_MAX);
		tmp_c += INT_MAX;
	}
}

void	ft_putstr(char *c)
{
	ft_putstr_fd(c, STDOUT_FILENO);
}

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	head;
	unsigned char	tail;

	if ((unsigned char)c <= 127)
		write(fd, &c, sizeof(c));
	else
	{
		head = 0b11000000 | (((unsigned char)c & 0b11000000) >> 6);
		tail = 0b10000000 | ((unsigned char)c & 0b00111111);
		write(fd, &head, sizeof(char));
		write(fd, &tail, sizeof(char));
	}
}

void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}

int	ft_strncmp(const char*s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cu_s1;
	const unsigned char	*cu_s2;

	cu_s1 = (const unsigned char *)s1;
	cu_s2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	i = 0;
	while (cu_s1[i] == cu_s2[i] && i < n - 1
		&& !(cu_s1[i] == '\0' && cu_s2[i] == '\0'))
		i++;
	return (cu_s1[i] - cu_s2[i]);
}


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	return (ft_strnstr(haystack, needle, ft_strlen(haystack)));
}

void	ft_putnbr_fd(int n, int fd)
{
	int	is_INT_MIN;

	is_INT_MIN = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == INT_MIN)
		{
			is_INT_MIN = 1;
			n++;
		}
		n *= -1;
	}
	if (0 <= n && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + is_INT_MIN + '0', fd);
	}
}

void	ft_putuinbr(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putuinbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, STDOUT_FILENO);
}

int ft_printf_helper(const char *format, va_list ap)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (ft_strncmp(&format[i], "%c", 2) == 0)
		{
			ft_putchar(va_arg(ap, int));
			i += 2;
		}	
		else if (ft_strncmp(&format[i], "%s", 2) == 0)
		{
			ft_putstr(va_arg(ap, char *));
			i += 2;
		}
		else if (ft_strncmp(&format[i], "%d", 2) == 0 || ft_strncmp(&format[i], "%i", 2) == 0)
		{
			ft_putnbr(va_arg(ap, int));
			i += 2;
		}
		else if (ft_strncmp(&format[i], "%u", 2) == 0)
		{
			ft_putuinbr(va_arg(ap, unsigned int));
			i += 2;
		}
		if (ft_strncmp(&format[i], "%%", 2) == 0)
		{
			ft_putchar('%');
			i += 2;
		}	
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_printf_helper(format, ap);
	va_end(ap);
	return (ret);
}

// // test
// int main(void) {
// 	ft_printf("%c\n", 'a');
// 	ft_printf("c\n", 'a');
// 	ft_printf("%s\n", "01234");
// 	ft_printf("s\n", "01234");
// 	ft_printf("%d\n", 1);
// 	ft_printf("%d %d\n", 10, -100);
// 	ft_printf("%i %i\n", 10, -100);
// 	ft_printf("%u\n", UINT_MAX);
// 	ft_printf("%u\n", 4294967296);
// 	ft_printf("%%\n");
// 	printf("%%\n");

// 	// segmentation fault case
// 	// printf("%s\n");
// 	// ft_printf("%s\n");
// }
