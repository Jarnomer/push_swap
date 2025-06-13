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

# define INITIAL_CAPACITY 100

/* ************************************************************************** */
/*																			  */
/*								STACK ELEMENT								  */
/*																			  */
/* 	num:			number value stored in element							  */
/* 	target_idx:		index of closest smaller/bigger element in other stack	  */
/* 	cost:			operation cost to trigger algorithm						  */
/* 	is_above:		index is above median? [y/n]							  */
/* 	is_deal:		push this element to other stack? [y/n]					  */
/*																			  */
/* ************************************************************************** */

typedef struct s_element
{
	int		num;
	int		target_idx;
	int		cost;
	bool	is_above;
	bool	is_deal;
}	t_element;

/* ************************************************************************** */
/*																			  */
/*								STACK ARRAY									  */
/*																			  */
/* 	data:			dynamic array of elements								  */
/* 	capacity:		allocated size of the array								  */
/* 	size:			current number of elements in stack						  */
/*																			  */
/* ************************************************************************** */

typedef struct s_stack
{
	t_element	*data;
	int			capacity;
	int			size;
}	t_stack;

void	split_argv(int argc, char *argv, t_stack **a);
int		stack_init(int argc, char **argv, t_stack *s, bool splitted);

void	sort_stack(t_stack *a, t_stack *b);
void	sort_prep_a(t_stack *a, t_stack *b);
void	sort_push_a(t_stack *a, t_stack *b);
void	sort_prep_b(t_stack *b, t_stack *a);
void	sort_push_b(t_stack *b, t_stack *a);

void	sa(t_stack *a, bool silent);
void	sb(t_stack *b, bool silent);
void	ss(t_stack *a, t_stack *b, bool silent);
void	pa(t_stack *a, t_stack *b, bool silent);
void	pb(t_stack *b, t_stack *a, bool silent);
void	ra(t_stack *a, bool silent);
void	rb(t_stack *b, bool silent);
void	rr(t_stack *a, t_stack *b, bool silent);
void	rra(t_stack *a, bool silent);
void	rrb(t_stack *b, bool silent);
void	rrr(t_stack *a, t_stack *b, bool silent);

bool	is_invalid_input(int argc, char **argv, bool splitted);
bool	is_duplicate_number(t_stack *a, int num);
void	error_occured(t_stack *a, t_stack *b);

bool	stack_sorted(t_stack *s);
int		find_smallest(t_stack *s);
int		find_largest(t_stack *s);
int		stack_size(t_stack *s);

/* New stack management functions */
t_stack	*stack_create(void);
void	stack_destroy(t_stack *stack);
int		stack_push_bottom(t_stack *stack, int value);
int		stack_resize(t_stack *stack);

#endif
