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

# include "./libft/libft.h"
# include <stdbool.h>

/* ************************************************************************** */
/*																			  */
/*                               STACK NODE                                   */
/*																			  */
/* 	num:			the number stored into stack							  */
/* 	idx:			running index of the node								  */
/* 	len:			total length of the stack								  */
/* 	above:			index above median, [y/n]								  */
/* 	cost:			operation cost to level both stacks						  */
/* 	deal:			push this node to other stack, [y/n]					  */
/* 	aim:			address to closest smaller or bigger 					  */
/* 	prev:			address to previous node in stack						  */
/* 	next:			address to next node in stack							  */
/*																			  */
/* ************************************************************************** */

typedef struct s_stack
{
	int				num;
	int				idx;
	int				len;
	bool			above;
	int				cost;
	bool			deal;
	struct s_stack	*aim;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                               SORTING                                      */
/* ************************************************************************** */

void	sort_stack(t_stack **a, t_stack **b);
void	sort_prep_a(t_stack *a, t_stack *b);
void	sort_push_a(t_stack **a, t_stack **b);
void	sort_prep_b(t_stack *b, t_stack *a);
void	sort_push_b(t_stack **b, t_stack **a);

/* ************************************************************************** */
/*                               COMMANDS                                     */
/* ************************************************************************** */

void	sa(t_stack **a, bool chkr);
void	sb(t_stack **b, bool chkr);
void	ss(t_stack **a, t_stack **b, bool chkr);
void	pa(t_stack **a, t_stack **b, bool chkr);
void	pb(t_stack **b, t_stack **a, bool chkr);
void	ra(t_stack **a, bool chkr);
void	rb(t_stack **b, bool chkr);
void	rr(t_stack **a, t_stack **b, bool chkr);
void	rra(t_stack **a, bool chkr);
void	rrb(t_stack **b, bool chkr);
void	rrr(t_stack **a, t_stack **b, bool chkr);

/* ************************************************************************** */
/*                              ERROR HANDLE                                  */
/* ************************************************************************** */

bool	invalid_input(int ac, char **av, bool splt);
bool	invalid_number(t_stack *a, int num);
void	error_occured(t_stack **a);
void	free_stack(t_stack **s);

/* ************************************************************************** */
/*                                UTILITIES                                   */
/* ************************************************************************** */

void	split_argv(int ac, char *av, t_stack **a);
bool	stack_init(int ac, char **av, t_stack **s, bool splt);
bool	stack_sorted(t_stack *s);
t_stack	*find_max(t_stack *s);
t_stack	*find_min(t_stack *s);
t_stack	*find_bottom(t_stack *s);
int		stack_len(t_stack *s);

#endif
