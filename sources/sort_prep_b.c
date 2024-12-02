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

#include <push_swap.h>

static void	update_target(t_stack *b, t_stack *a)
{
	t_stack	*temp;
	t_stack	*target;
	long	closest_larger;

	while (b)
	{
		temp = a;
		closest_larger = LONG_MAX;
		while (temp)
		{
			if (temp->num > b->num && temp->num < closest_larger)
			{
				closest_larger = temp->num;
				target = temp;
			}
			temp = temp->next;
		}
		if (closest_larger != LONG_MAX)
			b->target = target;
		else
			b->target = find_smallest(a);
		b = b->next;
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

void	sort_prep_b(t_stack *b, t_stack *a)
{
	prepare_stack(b, stack_size(b));
	prepare_stack(a, stack_size(a));
	update_target(b, a);
}
