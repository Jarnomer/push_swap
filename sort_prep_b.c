/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prep_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:47:52 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/16 13:38:55 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_aim(t_stack *b, t_stack *a)
{
	t_stack	*temp;
	t_stack	*deal;
	long	best;

	while (b)
	{
		temp = a;
		best = LONG_MAX;
		while (temp)
		{
			if (temp->num > b->num && temp->num < best)
			{
				best = temp->num;
				deal = temp;
			}
			temp = temp->next;
		}
		if (best != LONG_MAX)
			b->aim = deal;
		else
			b->aim = find_min(a);
		b = b->next;
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

void	sort_prep_b(t_stack *b, t_stack *a)
{
	update_index(b, stack_len(b));
	update_index(a, stack_len(a));
	update_aim(b, a);
}
