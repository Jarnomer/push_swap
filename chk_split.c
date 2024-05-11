/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:02:57 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/20 17:24:02 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	self_destruct(int ac, char ***arr)
{
	while (--ac >= 0)
		free((*arr)[ac]);
	free(*arr);
	*arr = NULL;
}

static void	exit_failure(int ac, char ***arr, t_stack **a)
{
	self_destruct(ac, arr);
	error_occured(a);
}

static int	argv_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++cnt;
		while (*s && *s != c)
			++s;
	}
	return (cnt);
}

void	split_argv(int ac, char *av, t_stack **a)
{
	char	**arr;

	ac = argv_count(av, ' ');
	arr = ft_split(av, ' ');
	if (!arr || invalid_input(ac, arr, true)
		|| !stack_init(ac, arr, a, true))
		exit_failure(ac, &arr, a);
	self_destruct(ac, &arr);
}
