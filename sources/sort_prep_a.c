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

#include <push_swap.h>

static void	update_deal(t_stack *s)
{
	t_stack	*bargain;
	int		deal;

	deal = INT_MAX;
	bargain = NULL;
	while (s)
	{
		if (s->cost < deal)
		{
			deal = s->cost;
			bargain = s;
		}
		s = s->next;
	}
	if (bargain)
		bargain->is_deal = true;
}

static void	update_cost(t_stack *a)
{
	int	ca;
	int	cb;

	while (a)
	{
		if (a->is_above)
			ca = a->index;
		else
			ca = a->size - a->index;
		if (a->target->is_above)
			cb = a->target->index;
		else
			cb = a->target->size - a->target->index;
		if (a->is_above != a->target->is_above)
			a->cost = ca + cb;
		else if (ca > cb)
			a->cost = ca;
		else
			a->cost = cb;
		if (a->is_lis)
			a->cost += 10000;
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
		s->is_deal = false;
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
	update_deal(a);
}
