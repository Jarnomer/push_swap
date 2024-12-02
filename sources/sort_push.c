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
			ra(a, false);
	if ((*a)->num != deal->num && !deal->is_above)
		while ((*a)->num != deal->num)
			rra(a, false);
	if ((*b)->num != deal->target->num && deal->target->is_above)
		while ((*b)->num != deal->target->num)
			rb(b, false);
	if ((*b)->num != deal->target->num && !deal->target->is_above)
		while ((*b)->num != deal->target->num)
			rrb(b, false);
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
			rr(a, b, false);
	else if (!deal->is_above && !deal->target->is_above)
		while ((*a)->num != deal->num && (*b)->num != deal->target->num)
			rrr(a, b, false);
	mix_rotate(a, b, deal);
	pb(b, a, false);
}

void	sort_push_b(t_stack **b, t_stack **a)
{
	if ((*b)->target->is_above)
		while ((*a)->num != (*b)->target->num)
			ra(a, false);
	if (!(*b)->target->is_above)
		while ((*b)->target->num != (*a)->num)
			rra(a, false);
	pa(a, b, false);
}
