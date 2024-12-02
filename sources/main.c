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

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (argc == 2 && *argv[1])
		split_argv(argc, argv[1], &a);
	else if ((argc == 2 && !*argv[1])
		|| is_invalid_input(argc, argv, false)
		|| stack_init(argc, argv, &a, false) == -1)
		error_occured(&a);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	ft_lstclear((t_list **)&a, NULL);
	return (EXIT_SUCCESS);
}
