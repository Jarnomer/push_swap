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

#include <push_swap.h>

static void	exit_failure(void ***arr, t_stack **a)
{
	ft_free_double(arr);
	error_exit(a);
}

static int	argv_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

void	split_argv(int argc, char *argv, t_stack **a)
{
	char	**arr;

	argc = argv_count(argv, ' ');
	arr = ft_split(argv, ' ');
	if (!arr || is_invalid_input(argc, arr, IS_SPLITTED)
		|| stack_init(argc, arr, a, IS_SPLITTED))
		exit_failure((void ***)&arr, a);
	ft_free_double((void ***)&arr);
}
