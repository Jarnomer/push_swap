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

static void	mix_rotate(t_stack **a, t_stack **b, t_stack *deal)
{
	if ((*a)->num != deal->num && deal->is_above)
		while ((*a)->num != deal->num)
			ra(a, IS_PUSH_SWAP);
	if ((*a)->num != deal->num && !deal->is_above)
		while ((*a)->num != deal->num)
			rra(a, IS_PUSH_SWAP);
	if ((*b)->num != deal->target->num && deal->target->is_above)
		while ((*b)->num != deal->target->num)
			rb(b, IS_PUSH_SWAP);
	if ((*b)->num != deal->target->num && !deal->target->is_above)
		while ((*b)->num != deal->target->num)
			rrb(b, IS_PUSH_SWAP);
}

static t_stack	*get_deal(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->is_deal)
			break ;
		a = a->next;
	}
	return (a);
}

void	sort_push_a(t_stack **a, t_stack **b)
{
	t_stack	*deal;

	deal = get_deal(*a);
	if (deal->is_above && deal->target->is_above)
		while ((*a)->num != deal->num && (*b)->num != deal->target->num)
			rr(a, b, IS_PUSH_SWAP);
	else if (!deal->is_above && !deal->target->is_above)
		while ((*a)->num != deal->num && (*b)->num != deal->target->num)
			rrr(a, b, IS_PUSH_SWAP);
	mix_rotate(a, b, deal);
	pb(b, a, IS_PUSH_SWAP);
}

void	sort_push_b(t_stack **b, t_stack **a)
{
	if ((*b)->target->is_above)
		while ((*a)->num != (*b)->target->num)
			ra(a, IS_PUSH_SWAP);
	if (!(*b)->target->is_above)
		while ((*b)->target->num != (*a)->num)
			rra(a, IS_PUSH_SWAP);
	pa(a, b, IS_PUSH_SWAP);
}
