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

#include <push_swap.h>

static void	swap(t_stack *s)
{
	t_element	temp;

	if (!s || s->size < 2)
		return ;
	temp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = temp;
}

void	sa(t_stack *a, bool silent)
{
	swap(a);
	if (!silent)
		ft_printf("sa\n");
}

void	sb(t_stack *b, bool silent)
{
	swap(b);
	if (!silent)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b, bool silent)
{
	swap(a);
	swap(b);
	if (!silent)
		ft_printf("ss\n");
}
