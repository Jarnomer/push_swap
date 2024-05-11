/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prep_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:47:52 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/16 13:38:17 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_deal(t_stack *s)
{
	t_stack	*bargain;
	int		deal;

	deal = INT_MAX;
	while (s)
	{
		if (s->cost < deal)
		{
			deal = s->cost;
			bargain = s;
		}
		s = s->next;
	}
	bargain->deal = true;
}

static void	update_cost(t_stack *a)
{
	while (a)
	{
		if (a->above)
			a->cost = a->idx;
		else
			a->cost = a->len - a->idx;
		if (a->aim->above)
			a->cost += a->aim->idx;
		else
			a->cost += a->aim->len - a->aim->idx;
		a = a->next;
	}
}

static void	update_aim(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*deal;
	long	best;

	while (a)
	{
		temp = b;
		best = LONG_MIN;
		while (temp)
		{
			if (temp->num < a->num && temp->num > best)
			{
				best = temp->num;
				deal = temp;
			}
			temp = temp->next;
		}
		if (best != LONG_MIN)
			a->aim = deal;
		else
			a->aim = find_max(b);
		a = a->next;
	}
}

static void	update_index(t_stack *s, int len)
{
	int	i;

	i = 0;
	while (s)
	{
		s->idx = i;
		s->len = len;
		if (i++ <= len / 2)
			s->above = true;
		else
			s->above = false;
		s = s->next;
	}
}

void	sort_prep_a(t_stack *a, t_stack *b)
{
	update_index(a, stack_len(a));
	update_index(b, stack_len(b));
	update_aim(a, b);
	update_cost(a);
	update_deal(a);
}
