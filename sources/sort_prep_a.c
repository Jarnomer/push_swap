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
	int	bargain_idx;
	int	min_cost;
	int	i;

	if (!s || s->size == 0)
		return ;
	min_cost = INT_MAX;
	bargain_idx = 0;
	i = 0;
	while (i < s->size)
	{
		s->data[i].is_deal = false;
		if (s->data[i].cost < min_cost)
		{
			min_cost = s->data[i].cost;
			bargain_idx = i;
		}
		i++;
	}
	if (bargain_idx < s->size)
		s->data[bargain_idx].is_deal = true;
}

static void	update_cost(t_stack *a, t_stack *b)
{
	int	i;
	int	a_cost;
	int	b_cost;
	int	target_idx;

	i = 0;
	while (i < a->size)
	{
		a_cost = i;
		if (!a->data[i].is_above)
			a_cost = a->size - i;
		target_idx = a->data[i].target_idx;
		if (target_idx >= 0 && target_idx < b->size)
		{
			b_cost = target_idx;
			if (!b->data[target_idx].is_above)
				b_cost = b->size - target_idx;
			a->data[i].cost = a_cost + b_cost;
		}
		else
			a->data[i].cost = INT_MAX;
		i++;
	}
}

static void	update_target(t_stack *a, t_stack *b)
{
	int		target_idx;
	long	closest_smaller;
	int		i;
	int		j;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		closest_smaller = LONG_MIN;
		target_idx = -1;
		while (j < b->size)
		{
			if (b->data[j].num < a->data[i].num 
				&& b->data[j].num > closest_smaller)
			{
				closest_smaller = b->data[j].num;
				target_idx = j;
			}
			j++;
		}
		if (target_idx != -1)
			a->data[i].target_idx = target_idx;
		else
			a->data[i].target_idx = find_largest(b);
		i++;
	}
}

static void	prepare_stack(t_stack *s)
{
	int	i;
	int	median;

	if (!s || s->size == 0)
		return ;
	median = (s->size - 1) / 2;
	i = 0;
	while (i < s->size)
	{
		if (i <= median)
			s->data[i].is_above = true;
		else
			s->data[i].is_above = false;
		i++;
	}
}

void	sort_prep_a(t_stack *a, t_stack *b)
{
	prepare_stack(a);
	prepare_stack(b);
	update_target(a, b);
	update_cost(a, b);
	update_is_deal(a);
}
