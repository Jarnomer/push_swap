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
	int	i;

	if (!s || s->size < 2)
		return (true);
	i = 0;
	while (i < s->size - 1)
	{
		if (s->data[i].num > s->data[i + 1].num)
			return (false);
		i++;
	}
	return (true);
}

int	find_smallest(t_stack *s)
{
	int	min_idx;
	int	min_val;
	int	i;

	if (!s || s->size == 0)
		return (-1);
	min_val = INT_MAX;
	min_idx = 0;
	i = 0;
	while (i < s->size)
	{
		if (s->data[i].num < min_val)
		{
			min_val = s->data[i].num;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	find_largest(t_stack *s)
{
	int	max_idx;
	int	max_val;
	int	i;

	if (!s || s->size == 0)
		return (-1);
	max_val = INT_MIN;
	max_idx = 0;
	i = 0;
	while (i < s->size)
	{
		if (s->data[i].num > max_val)
		{
			max_val = s->data[i].num;
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

int	stack_size(t_stack *s)
{
	if (!s)
		return (0);
	return (s->size);
}
