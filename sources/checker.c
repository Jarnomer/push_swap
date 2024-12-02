/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:18:07 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/15 18:03:25 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	self_destruct(t_stack **a, t_stack **b, char **cmd)
{
	ft_free_single((void **)cmd);
	ft_lstclear((t_list **)a, NULL);
	ft_lstclear((t_list **)b, NULL);
}

static void	exit_failure(t_stack **a, t_stack **b, char **cmd)
{
	self_destruct(a, b, cmd);
	error_occured(a);
}

static void	trigger_command(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, true);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, true);
	else
		exit_failure(a, b, &cmd);
}

static void	build_stack(int argc, char **argv, t_stack **a)
{
	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2 && *argv[1])
		split_argv(argc, argv[1], a);
	else if ((argc == 2 && !*argv[1])
		|| is_invalid_input(argc, argv, false)
		|| stack_init(argc, argv, a, false) == -1)
		error_occured(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;
	int		len;

	a = NULL;
	b = NULL;
	build_stack(argc, argv, &a);
	len = stack_size(a);
	while (true)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		trigger_command(&a, &b, cmd);
		free(cmd);
	}
	if (stack_sorted(a) && stack_size(a) == len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	self_destruct(&a, &b, &cmd);
	return (EXIT_SUCCESS);
}
