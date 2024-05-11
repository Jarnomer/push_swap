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

#include "push_swap.h"

static long	custom_atol(const char *str)
{
	long	num;
	long	sgn;

	num = 0;
	sgn = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
		sgn = 44 - *str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str++ - '0';
		if (num * sgn > INT_MAX || num * sgn < INT_MIN)
			return (LONG_MAX);
	}
	return (num * sgn);
}

static t_stack	*stack_new(int num)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->idx = -1;
	new->len = -1;
	new->cost = -1;
	return (new);
}

static void	stack_add(t_stack **top, t_stack *new)
{
	t_stack	*bottom;

	if (!top || !new)
		return ;
	else if (!*top)
		*top = new;
	else
	{
		bottom = find_bottom(*top);
		bottom->next = new;
		new->prev = bottom;
	}
}

bool	stack_init(int ac, char **av, t_stack **s, bool splt)
{
	t_stack	*new;
	long	num;
	int		i;

	i = 0;
	if (splt)
		i = -1;
	while (++i < ac)
	{
		num = custom_atol(av[i]);
		new = stack_new((int)num);
		if (num == LONG_MAX || !new
			|| invalid_number(*s, (int)num))
			return (free(new), false);
		stack_add(s, new);
	}
	return (true);
}
