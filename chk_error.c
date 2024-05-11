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

#include "push_swap.h"

void	free_stack(t_stack **s)
{
	t_stack	*temp;

	if (!s)
		return ;
	while (*s)
	{
		temp = (*s)->next;
		free(*s);
		*s = temp;
	}
	*s = NULL;
}

void	error_occured(t_stack **a)
{
	free_stack(a);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

bool	invalid_number(t_stack *a, int num)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->num == num)
			return (true);
		a = a->next;
	}
	return (false);
}

bool	invalid_input(int ac, char **av, bool splt)
{
	int		i;
	int		j;

	i = 0;
	if (splt)
		i = -1;
	while (++i < ac)
	{
		if ((!ft_isdigit(*av[i]) && *av[i] != '-' && *av[i] != '+')
			|| (ft_strlen(av[i]) == 1 && (*av[i] == '-' || *av[i] == '+')))
			return (true);
		j = 0;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (true);
	}
	return (false);
}
