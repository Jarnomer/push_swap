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

#include "push_swap.h"

static void	self_destruct(t_stack **a, t_stack **b, char **cmd)
{
	free(*cmd);
	free_stack(b);
	free_stack(a);
}

static void	exit_failure(t_stack **a, t_stack **b, char **cmd)
{
	self_destruct(a, b, cmd);
	error_occured(a);
}

static void	trigger_command(t_stack **a, t_stack **b, char *cmd, int len)
{
	if (ft_strnstr(cmd, "pa\n", len) && len == 3)
		pa(a, b, true);
	else if (ft_strnstr(cmd, "pb\n", len) && len == 3)
		pb(b, a, true);
	else if (ft_strnstr(cmd, "sa\n", len) && len == 3)
		sa(a, true);
	else if (ft_strnstr(cmd, "sb\n", len) && len == 3)
		sb(b, true);
	else if (ft_strnstr(cmd, "ss\n", len) && len == 3)
		ss(a, b, true);
	else if (ft_strnstr(cmd, "ra\n", len) && len == 3)
		ra(a, true);
	else if (ft_strnstr(cmd, "rb\n", len) && len == 3)
		rb(b, true);
	else if (ft_strnstr(cmd, "rr\n", len) && len == 3)
		rr(a, b, true);
	else if (ft_strnstr(cmd, "rra\n", len) && len == 4)
		rra(a, true);
	else if (ft_strnstr(cmd, "rrb\n", len) && len == 4)
		rrb(b, true);
	else if (ft_strnstr(cmd, "rrr\n", len) && len == 4)
		rrr(a, b, true);
	else
		exit_failure(a, b, &cmd);
}

static void	build_stack(int ac, char **av, t_stack **a)
{
	if (ac < 2)
		exit(EXIT_FAILURE);
	else if (ac == 2 && *av[1])
		split_argv(ac, av[1], a);
	else if ((ac == 2 && !*av[1])
		|| invalid_input(ac, av, false)
		|| !stack_init(ac, av, a, false))
		error_occured(a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;
	int		len;

	a = NULL;
	b = NULL;
	build_stack(ac, av, &a);
	len = stack_len(a);
	while (true)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (!cmd)
			break ;
		trigger_command(&a, &b, cmd, ft_strlen(cmd));
		free(cmd);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	self_destruct(&a, &b, &cmd);
	return (EXIT_SUCCESS);
}
