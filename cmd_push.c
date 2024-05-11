/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:23:18 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/14 16:10:44 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!dst || !src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = tmp;
		(*dst)->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_stack **a, t_stack **b, bool chkr)
{
	push(a, b);
	if (!chkr)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool chkr)
{
	push(b, a);
	if (!chkr)
		ft_printf("pb\n");
}
