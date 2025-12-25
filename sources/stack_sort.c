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
	t_stack	*smallest;
	t_stack	*temp;
	int		pos;
	int		size;

	pos = 0;
	temp = *a;
	size = stack_size(*a);
	if (size <= 1)
		return ;
	smallest = find_smallest(*a);
	while (temp && temp != smallest)
	{
		temp = temp->next;
		pos++;
	}
	while ((*a)->num != smallest->num)
	{
		if (pos <= size / 2)
			ra(a, IS_PUSH_SWAP);
		else
			rra(a, IS_PUSH_SWAP);
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

static void	sort_three(t_stack **a, int len)
{
	t_stack	*largest;

	while (!stack_sorted(*a))
	{
		largest = find_largest(*a);
		if (len == 2)
			sa(a, IS_PUSH_SWAP);
		if (len == 3 && *a == largest)
			ra(a, IS_PUSH_SWAP);
		else if (len == 3 && (*a)->next == largest)
			rra(a, IS_PUSH_SWAP);
		if (len == 3 && (*a)->num > (*a)->next->num)
			sa(a, IS_PUSH_SWAP);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 3)
	{
		sort_three(a, size);
		return ;
	}
	if (size > 5)
		mark_lis(*a);
	while (!stack_sorted(*a) && stack_size(*a) > 3 && stack_size(*b) < 2)
		pb(b, a, IS_PUSH_SWAP);
	while (!stack_sorted(*a) && stack_size(*a) > 3)
		push_a_to_b(a, b);
	sort_three(a, stack_size(*a));
	while (*b)
		push_b_to_a(b, a);
	stack_align(a);
}
