/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:46:40 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/11 13:19:26 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	stack_align(t_stack *a)
{
	int	smallest_idx;
	int	rotations;

	if (stack_size(a) <= 1)
		return ;
	smallest_idx = find_smallest(a);
	if (smallest_idx == 0)
		return ;
	if (smallest_idx <= a->size / 2)
	{
		rotations = smallest_idx;
		while (rotations-- > 0)
			ra(a, false);
	}
	else
	{
		rotations = a->size - smallest_idx;
		while (rotations-- > 0)
			rra(a, false);
	}
}

static void	push_b_to_a(t_stack *b, t_stack *a)
{
	sort_prep_b(b, a);
	sort_push_b(b, a);
}

static void	push_a_to_b(t_stack *a, t_stack *b)
{
	sort_prep_a(a, b);
	sort_push_a(a, b);
}

static void	sort_small(t_stack *a, int len)
{
	int	largest_idx;

	while (!stack_sorted(a))
	{
		largest_idx = find_largest(a);
		if (len == 2)
			sa(a, false);
		if (len == 3 && largest_idx == 0)
			ra(a, false);
		else if (len == 3 && largest_idx == 1)
			rra(a, false);
		if (len == 3 && a->data[0].num > a->data[1].num)
			sa(a, false);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	while (!stack_sorted(a) && stack_size(a) > 3 && stack_size(b) < 2)
		pb(b, a, false);
	while (!stack_sorted(a) && stack_size(a) > 3)
		push_a_to_b(a, b);
	sort_small(a, stack_size(a));
	while (b->size > 0)
		push_b_to_a(b, a);
	stack_align(a);
}
