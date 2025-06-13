/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:36:27 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/16 13:30:16 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	find_deal_index(t_stack *a)
{
	int	i;

	if (!a)
		return (-1);
	i = 0;
	while (i < a->size)
	{
		if (a->data[i].is_deal)
			return (i);
		i++;
	}
	return (-1);
}

static void	rotate_to_top(t_stack *stack, int target_value, 
	void (*rotate)(t_stack *, bool), void (*reverse)(t_stack *, bool))
{
	int	i;
	int	pos;

	pos = -1;
	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i].num == target_value)
		{
			pos = i;
			break ;
		}
		i++;
	}
	if (pos == -1 || pos == 0)
		return ;
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
			rotate(stack, false);
	}
	else
	{
		pos = stack->size - pos;
		while (pos-- > 0)
			reverse(stack, false);
	}
}

void	sort_push_a(t_stack *a, t_stack *b)
{
	int	deal_idx;
	int	deal_value;
	int	target_value;

	deal_idx = find_deal_index(a);
	if (deal_idx == -1)
		return ;
	deal_value = a->data[deal_idx].num;
	target_value = b->data[a->data[deal_idx].target_idx].num;
	rotate_to_top(a, deal_value, ra, rra);
	rotate_to_top(b, target_value, rb, rrb);
	pb(b, a, false);
}

void	sort_push_b(t_stack *b, t_stack *a)
{
	int	target_value;

	if (b->size == 0)
		return ;
	target_value = a->data[b->data[0].target_idx].num;
	rotate_to_top(a, target_value, ra, rra);
	pa(a, b, false);
}
