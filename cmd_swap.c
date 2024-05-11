/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:37:29 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/16 13:46:54 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **s)
{
	if (!s || !*s || !(*s)->next)
		return ;
	*s = (*s)->next;
	(*s)->prev->prev = *s;
	(*s)->prev->next = (*s)->next;
	if ((*s)->next)
		(*s)->next->prev = (*s)->prev;
	(*s)->next = (*s)->prev;
	(*s)->prev = NULL;
}

void	sa(t_stack**a, bool chkr)
{
	swap(a);
	if (!chkr)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool chkr)
{
	swap(b);
	if (!chkr)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool chkr)
{
	swap(a);
	swap(b);
	if (!chkr)
		ft_printf("ss\n");
}
