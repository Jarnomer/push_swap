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

#include <push_swap.h>

static void	rotate(t_stack **s)
{
	t_stack	*bottom;

	if (!s || !*s || !(*s)->next)
		return ;
	bottom = (t_stack *)ft_lstlast((t_list *)*s);
	bottom->next = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	bottom->next->prev = bottom;
	bottom->next->next = NULL;
}

void	ra(t_stack **a, bool silent)
{
	rotate(a);
	if (!silent)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool silent)
{
	rotate(b);
	if (!silent)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool silent)
{
	rotate(a);
	rotate(b);
	if (!silent)
		ft_printf("rr\n");
}
