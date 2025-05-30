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

#include <push_swap.h>

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*temp;

	if (!dst || !src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		(*dst)->next = NULL;
	}
	else
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_stack **a, t_stack **b, bool silent)
{
	push(a, b);
	if (!silent)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool silent)
{
	push(b, a);
	if (!silent)
		ft_printf("pb\n");
}
