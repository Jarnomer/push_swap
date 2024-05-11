/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:40:54 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/12 20:18:58 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *s)
{
	if (!s)
		return (true);
	while (s->next)
	{
		if (s->num > s->next->num)
			return (false);
		s = s->next;
	}
	return (true);
}

t_stack	*find_min(t_stack *s)
{
	t_stack	*deal;
	int		min;

	if (!s)
		return (NULL);
	min = INT_MAX;
	while (s)
	{
		if (s->num < min)
		{
			min = s->num;
			deal = s;
		}
		s = s->next;
	}
	return (deal);
}

t_stack	*find_max(t_stack *s)
{
	t_stack	*deal;
	int		max;

	if (!s)
		return (NULL);
	max = INT_MIN;
	while (s)
	{
		if (s->num > max)
		{
			max = s->num;
			deal = s;
		}
		s = s->next;
	}
	return (deal);
}

t_stack	*find_bottom(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

int	stack_len(t_stack *s)
{
	if (!s)
		return (0);
	else
		return (1 + stack_len(s->next));
}
