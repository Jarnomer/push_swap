/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:00:00 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/11 14:00:00 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	*stack_to_array(t_stack *s, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (s)
	{
		arr[i++] = s->num;
		s = s->next;
	}
	return (arr);
}

static int	*compute_lis_dp(int *arr, int size)
{
	int	*dp;
	int	i;
	int	j;

	dp = malloc(sizeof(int) * size);
	if (!dp)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		dp[i] = 1;
		j = -1;
		while (++j < i)
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
	}
	return (dp);
}

static int	find_lis_end_idx(int *dp, int size)
{
	int	max_idx;
	int	i;

	max_idx = 0;
	i = 0;
	while (++i < size)
		if (dp[i] > dp[max_idx])
			max_idx = i;
	return (max_idx);
}

static void	mark_lis_nodes(t_stack *s, int *arr, int *dp, int end)
{
	t_stack	*node;
	int		lis_len;
	int		prev_val;
	int		i;

	lis_len = dp[end];
	prev_val = INT_MAX;
	i = end + 1;
	while (--i >= 0 && lis_len > 0)
	{
		if (dp[i] == lis_len && arr[i] < prev_val)
		{
			node = s;
			while (node && node->num != arr[i])
				node = node->next;
			if (node)
				node->is_lis = true;
			prev_val = arr[i];
			lis_len--;
		}
	}
}

void	mark_lis(t_stack *a)
{
	int	*arr;
	int	*dp;
	int	size;
	int	end_idx;

	size = stack_size(a);
	arr = stack_to_array(a, size);
	if (!arr)
		return ;
	dp = compute_lis_dp(arr, size);
	if (!dp)
	{
		free(arr);
		return ;
	}
	end_idx = find_lis_end_idx(dp, size);
	mark_lis_nodes(a, arr, dp, end_idx);
	free(arr);
	free(dp);
}
