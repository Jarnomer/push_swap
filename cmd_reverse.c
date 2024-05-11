/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:11:42 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/14 16:11:00 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **s)
{
	t_stack	*btm;

	if (!s || !*s || !(*s)->next)
		return ;
	btm = find_bottom(*s);
	btm->prev->next = NULL;
	btm->next = *s;
	btm->prev = NULL;
	*s = btm;
	btm->next->prev = btm;
}

void	rra(t_stack **a, bool chkr)
{
	reverse(a);
	if (!chkr)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool chkr)
{
	reverse(b);
	if (!chkr)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool chkr)
{
	reverse(a);
	reverse(b);
	if (!chkr)
		ft_printf("rrr\n");
}
