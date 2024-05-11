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

#include "push_swap.h"

static void	mix_rotate(t_stack **a, t_stack **b, t_stack *deal)
{
	if ((*a)->num != deal->num && deal->above)
		while ((*a)->num != deal->num)
			ra(a, false);
	if ((*a)->num != deal->num && !deal->above)
		while ((*a)->num != deal->num)
			rra(a, false);
	if ((*b)->num != deal->aim->num && deal->aim->above)
		while ((*b)->num != deal->aim->num)
			rb(b, false);
	if ((*b)->num != deal->aim->num && !deal->aim->above)
		while ((*b)->num != deal->aim->num)
			rrb(b, false);
}

static t_stack	*get_deal(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->deal)
			break ;
		a = a->next;
	}
	return (a);
}

void	sort_push_a(t_stack **a, t_stack **b)
{
	t_stack	*deal;

	deal = get_deal(*a);
	if (deal->above && deal->aim->above)
		while ((*a)->num != deal->num && (*b)->num != deal->aim->num)
			rr(a, b, false);
	else if (!deal->above && !deal->aim->above)
		while ((*a)->num != deal->num && (*b)->num != deal->aim->num)
			rrr(a, b, false);
	mix_rotate(a, b, deal);
	pb(b, a, false);
}

void	sort_push_b(t_stack **b, t_stack **a)
{
	if ((*b)->aim->above)
		while ((*a)->num != (*b)->aim->num)
			ra(a, false);
	if (!(*b)->aim->above)
		while ((*b)->aim->num != (*a)->num)
			rra(a, false);
	pa(a, b, false);
}
