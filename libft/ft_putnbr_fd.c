/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:35:06 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/06 20:23:00 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	st_get_div(long n)
{
	long	div;
	int		i;

	i = 0;
	div = 1;
	if (n < 0)
		div *= -1;
	while (n != 0 && ++i)
		n /= 10;
	while (--i > 0)
		div *= 10;
	return (div);
}

int	ft_putnbr_fd(long n, int fd)
{
	long	div;
	int		len;

	len = 0;
	div = st_get_div(n);
	if (n < 0 && ++len)
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
	while (div != 0 && ++len)
	{
		if (ft_putchar_fd(n / div + '0', fd) < 0)
			return (-1);
		n %= div;
		div /= 10;
	}
	return (len);
}
