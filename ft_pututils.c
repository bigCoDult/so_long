/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:31:29 by sanbaek           #+#    #+#             */
/*   Updated: 2024/05/10 15:31:29 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putll_fd(long long int n, int fd)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		count++;
	}
	if (n > 9)
		count += ft_putll_fd(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
	return (count);
}

int	ft_puthex_fd(int is_x, long long unsigned int n, int fd)
{
	char	digit;
	int		count;

	digit = '\0';
	count = 1;
	if (n >= 16)
		count += ft_puthex_fd(is_x, n / 16, fd);
	n = n % 16;
	if (n < 10)
		digit = n + '0';
	else if (is_x == 'x')
		digit = n + 'a' - 10;
	else if (is_x == 'X')
		digit = n + 'A' - 10;
	write(fd, &digit, 1);
	return (count);
}
