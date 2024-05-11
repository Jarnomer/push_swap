/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:42:58 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/21 15:29:33 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*btm;

	if (!s || !*s || !(*s)->next)
		return ;
	btm = find_bottom(*s);
	btm->next = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	btm->next->prev = btm;
	btm->next->next = NULL;
}

void	ra(t_stack **a, bool chkr)
{
	rotate(a);
	if (!chkr)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool chkr)
{
	rotate(b);
	if (!chkr)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool chkr)
{
	rotate(a);
	rotate(b);
	if (!chkr)
		ft_printf("rr\n");
}
