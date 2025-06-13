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

static void	push(t_stack *dst, t_stack *src)
{
	t_element	temp;
	int			i;

	if (!dst || !src || src->size == 0)
		return ;
	if (dst->size >= dst->capacity)
		if (stack_resize(dst) == -1)
			return ;
	temp = src->data[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = temp;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b, bool silent)
{
	push(a, b);
	if (!silent)
		ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a, bool silent)
{
	push(b, a);
	if (!silent)
		ft_printf("pb\n");
}
