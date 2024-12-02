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

static void	update_is_deal(t_stack *s)
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
	bargain->is_deal = true;
}

static void	update_cost(t_stack *a)
{
	while (a)
	{
		if (a->is_above)
			a->cost = a->index;
		else
			a->cost = a->size - a->index;
		if (a->target->is_above)
			a->cost += a->target->index;
		else
			a->cost += a->target->size - a->target->index;
		a = a->next;
	}
}

static void	update_target(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*target;
	long	closest_smaller;

	while (a)
	{
		temp = b;
		closest_smaller = LONG_MIN;
		while (temp)
		{
			if (temp->num < a->num && temp->num > closest_smaller)
			{
				closest_smaller = temp->num;
				target = temp;
			}
			temp = temp->next;
		}
		if (closest_smaller != LONG_MIN)
			a->target = target;
		else
			a->target = find_largest(b);
		a = a->next;
	}
}

static void	prepare_stack(t_stack *s, int size)
{
	int	i;

	i = 0;
	while (s)
	{
		s->index = i;
		s->size = size;
		if (i++ <= size / 2)
			s->is_above = true;
		else
			s->is_above = false;
		s = s->next;
	}
}

void	sort_prep_a(t_stack *a, t_stack *b)
{
	prepare_stack(a, stack_size(a));
	prepare_stack(b, stack_size(b));
	update_target(a, b);
	update_cost(a);
	update_is_deal(a);
}
