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
	int		target_idx;
	long	closest_larger;
	int		i;
	int		j;

	i = 0;
	while (i < b->size)
	{
		j = 0;
		closest_larger = LONG_MAX;
		target_idx = -1;
		while (j < a->size)
		{
			if (a->data[j].num > b->data[i].num 
				&& a->data[j].num < closest_larger)
			{
				closest_larger = a->data[j].num;
				target_idx = j;
			}
			j++;
		}
		if (target_idx != -1)
			b->data[i].target_idx = target_idx;
		else
			b->data[i].target_idx = find_smallest(a);
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

void	sort_prep_b(t_stack *b, t_stack *a)
{
	prepare_stack(b);
	prepare_stack(a);
	update_target(b, a);
}
