/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:12:25 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/11 13:32:05 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

/* ************************************************************************** */
/*																			  */
/*								STACK NODE									  */
/*																			  */
/* 	target:			closest smaller or bigger node							  */
/* 	prev:			previous node in stack									  */
/* 	next:			next node in stack										  */
/* 	num:			number value stored in node								  */
/* 	index:			running index of the node								  */
/* 	cost:			operation cost to trigger algorithm						  */
/* 	size:			total size of the stack									  */
/* 	is_above:		index is above median? [y/n]							  */
/* 	is_deal:		push this node to other stack? [y/n]					  */
/*																			  */
/* ************************************************************************** */

typedef struct s_stack
{
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				num;
	int				index;
	int				cost;
	int				size;
	bool			is_above;
	bool			is_deal;
}	t_stack;

void	split_argv(int argc, char *argv, t_stack **a);
int		stack_init(int argc, char **argv, t_stack **s, bool splitted);

void	sort_stack(t_stack **a, t_stack **b);
void	sort_prep_a(t_stack *a, t_stack *b);
void	sort_push_a(t_stack **a, t_stack **b);
void	sort_prep_b(t_stack *b, t_stack *a);
void	sort_push_b(t_stack **b, t_stack **a);

void	sa(t_stack **a, bool silent);
void	sb(t_stack **b, bool silent);
void	ss(t_stack **a, t_stack **b, bool silent);
void	pa(t_stack **a, t_stack **b, bool silent);
void	pb(t_stack **b, t_stack **a, bool silent);
void	ra(t_stack **a, bool silent);
void	rb(t_stack **b, bool silent);
void	rr(t_stack **a, t_stack **b, bool silent);
void	rra(t_stack **a, bool silent);
void	rrb(t_stack **b, bool silent);
void	rrr(t_stack **a, t_stack **b, bool silent);

bool	is_invalid_input(int argc, char **argv, bool splitted);
bool	is_duplicate_number(t_stack *a, int num);
void	error_occured(t_stack **a);

bool	stack_sorted(t_stack *s);
t_stack	*find_smallest(t_stack *s);
t_stack	*find_largest(t_stack *s);
int		stack_size(t_stack *s);

#endif
