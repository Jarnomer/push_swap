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

static void	stack_align(t_stack **a)
{
	if (stack_size(*a) == 1)
		return ;
	while ((*a)->num != find_smallest(*a)->num)
	{
		if (find_smallest(*a)->is_above)
			ra(a, false);
		else
			rra(a, false);
	}
}

static void	push_b_to_a(t_stack **b, t_stack **a)
{
	sort_prep_b(*b, *a);
	sort_push_b(b, a);
}

static void	push_a_to_b(t_stack **a, t_stack **b)
{
	sort_prep_a(*a, *b);
	sort_push_a(a, b);
}

static void	sort_small(t_stack **a, int len)
{
	t_stack	*largest;

	while (!stack_sorted(*a))
	{
		largest = find_largest(*a);
		if (len == 2)
			sa(a, false);
		if (len == 3 && *a == largest)
			ra(a, false);
		else if (len == 3 && (*a)->next == largest)
			rra(a, false);
		if (len == 3 && (*a)->num > (*a)->next->num)
			sa(a, false);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	while (!stack_sorted(*a) && stack_size(*a) > 3 && stack_size(*b) < 2)
		pb(b, a, false);
	while (!stack_sorted(*a) && stack_size(*a) > 3)
		push_a_to_b(a, b);
	sort_small(a, stack_size(*a));
	while (*b)
		push_b_to_a(b, a);
	stack_align(a);
}
