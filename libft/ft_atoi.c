/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:31 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/22 16:29:13 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	num;
	int		sgn;

	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
		sgn = 44 - *str++;
	else
		sgn = 1;
	num = 0;
	while (ft_isdigit(*str))
	{
		if (num > LONG_MAX && sgn < 0)
			return (0);
		else if (num > LONG_MAX && sgn > 0)
			return (-1);
		num = num * 10 + *str++ - '0';
	}
	return ((int)num * sgn);
}
