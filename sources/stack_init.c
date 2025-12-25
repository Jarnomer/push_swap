/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:09:41 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/11 13:28:04 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long	ft_atol(const char *str)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (ft_issign(*str))
		sign = 44 - *str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str++ - '0';
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (LONG_MAX);
	}
	return (num * sign);
}

int	stack_init(int argc, char **argv, t_stack **s, bool splitted)
{
	t_stack	*new;
	long	num;
	int		i;

	i = 0;
	if (splitted == true)
		i -= 1;
	while (++i < argc)
	{
		num = ft_atol(argv[i]);
		if (num == LONG_MAX || is_duplicate_number(*s, (int)num))
			return (1);
		new = ft_calloc(1, sizeof(t_stack));
		if (!new)
			return (1);
		new->num = (int)num;
		new->prev = stack_last(*s);
		stack_add(s, new);
	}
	return (0);
}
