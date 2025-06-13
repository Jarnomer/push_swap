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

static void	reverse(t_stack *s)
{
	t_element	temp;
	int			i;

	if (!s || s->size < 2)
		return ;
	temp = s->data[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = temp;
}

void	rra(t_stack *a, bool silent)
{
	reverse(a);
	if (!silent)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, bool silent)
{
	reverse(b);
	if (!silent)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, bool silent)
{
	reverse(a);
	reverse(b);
	if (!silent)
		ft_printf("rrr\n");
}
