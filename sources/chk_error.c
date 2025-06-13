/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:17:15 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/21 15:23:21 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error_occured(t_stack *a, t_stack *b)
{
	if (a)
		stack_destroy(a);
	if (b)
		stack_destroy(b);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	is_duplicate_number(t_stack *a, int num)
{
	int	i;

	if (!a)
		return (false);
	i = 0;
	while (i < a->size)
	{
		if (a->data[i].num == num)
			return (true);
		i++;
	}
	return (false);
}

bool	is_invalid_input(int argc, char **argv, bool splitted)
{
	int	i;
	int	j;

	i = 0;
	if (splitted)
		--i;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && ft_issign(*argv[i]))
			return (true);
		else if (!ft_isdigit(*argv[i]) && !ft_issign(*argv[i]))
			return (true);
		j = 1;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				return (true);
	}
	return (false);
}
