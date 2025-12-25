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

# define IS_CHECKER    true
# define IS_PUSH_SWAP  false

# define IS_SPLITTED   true
# define NOT_SPLITTED  false

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
/* 	is_lis:		    node is part of longest increasing subsequence? [y/n]     */
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
	bool			is_lis;
}	t_stack;

/* ************************************************************************** */
/*                                   INIT                                     */
/* ************************************************************************** */

void	split_argv(int argc, char *argv, t_stack **a);
int		stack_init(int argc, char **argv, t_stack **s, bool splitted);

/* ************************************************************************** */
/*                               SORTING                                      */
/* ************************************************************************** */

void	sort_stack(t_stack **a, t_stack **b);
void	sort_prep_a(t_stack *a, t_stack *b);
void	sort_push_a(t_stack **a, t_stack **b);
void	sort_prep_b(t_stack *b, t_stack *a);
void	sort_push_b(t_stack **b, t_stack **a);
void	mark_lis(t_stack *a);

/* ************************************************************************** */
/*                               COMMANDS                                     */
/* ************************************************************************** */

void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

/* ************************************************************************** */
/*                             ERROR HANDLING                                 */
/* ************************************************************************** */

bool	is_invalid_input(int argc, char **argv, bool splitted);
bool	is_duplicate_number(t_stack *a, int num);
void	error_exit(t_stack **a);

/* ************************************************************************** */
/*                             STACK UTILITIES                                */
/* ************************************************************************** */

bool	stack_sorted(t_stack *s);
t_stack	*stack_last(t_stack *s);
void	stack_add(t_stack **s, t_stack *new);
void	stack_clear(t_stack **s);
t_stack	*find_smallest(t_stack *s);
t_stack	*find_largest(t_stack *s);
int		stack_size(t_stack *s);

#endif
