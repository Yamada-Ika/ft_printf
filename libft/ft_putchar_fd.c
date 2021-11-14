/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 23:47:30 by iyamada           #+#    #+#             */
/*   Updated: 2021/10/25 10:55:31 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
