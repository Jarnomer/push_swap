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

#include <push_swap.h>

static void	reverse(t_stack **s)
{
	t_stack	*bottom;

	if (!s || !*s || !(*s)->next)
		return ;
	bottom = (t_stack *)ft_lstlast((t_list *)*s);
	bottom->prev->next = NULL;
	bottom->next = *s;
	bottom->prev = NULL;
	*s = bottom;
	bottom->next->prev = bottom;
}

void	rra(t_stack **a, bool checker)
{
	reverse(a);
	if (!checker)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool checker)
{
	reverse(b);
	if (!checker)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse(a);
	reverse(b);
	if (!checker)
		ft_printf("rrr\n");
}
