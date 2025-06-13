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

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_create();
	b = stack_create();
	if (!a || !b)
	{
		stack_destroy(a);
		stack_destroy(b);
		return (EXIT_FAILURE);
	}
	if (argc < 2)
	{
		stack_destroy(a);
		stack_destroy(b);
		return (EXIT_FAILURE);
	}
	else if (argc == 2 && *argv[1])
		split_argv(argc, argv[1], &a);
	else if ((argc == 2 && !*argv[1])
		|| is_invalid_input(argc, argv, false)
		|| stack_init(argc, argv, a, false) == -1)
	{
		stack_destroy(a);
		stack_destroy(b);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!stack_sorted(a))
		sort_stack(a, b);
	stack_destroy(a);
	stack_destroy(b);
	return (EXIT_SUCCESS);
}
