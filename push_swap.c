/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:13:26 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/22 11:08:16 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (EXIT_FAILURE);
	else if (ac == 2 && *av[1])
		split_argv(ac, av[1], &a);
	else if ((ac == 2 && !*av[1])
		|| invalid_input(ac, av, false)
		|| !stack_init(ac, av, &a, false))
		error_occured(&a);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	return (EXIT_SUCCESS);
}
