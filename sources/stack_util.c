/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:40:54 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/12 20:18:58 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	stack_sorted(t_stack *s)
{
	if (!s)
		return (true);
	while (s->next)
	{
		if (s->num > s->next->num)
			return (false);
		s = s->next;
	}
	return (true);
}

t_stack	*find_smallest(t_stack *s)
{
	t_stack	*lowest;
	int		min;

	if (!s)
		return (NULL);
	min = INT_MAX;
	while (s)
	{
		if (s->num < min)
		{
			min = s->num;
			lowest = s;
		}
		s = s->next;
	}
	return (lowest);
}

t_stack	*find_largest(t_stack *s)
{
	t_stack	*largest;
	int		max;

	if (!s)
		return (NULL);
	max = INT_MIN;
	while (s)
	{
		if (s->num > max)
		{
			max = s->num;
			largest = s;
		}
		s = s->next;
	}
	return (largest);
}

int	stack_size(t_stack *s)
{
	return (ft_lstsize((t_list *)s));
}
