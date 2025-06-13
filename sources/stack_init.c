/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:09:41 by jmertane          #+#    #+#             */
/*   Updated: 2024/05/11 13:28:04 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long	custom_atol(const char *str)
{
	long	num;
	long	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (ft_issign(*str))
		sign = 44 - *str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + *str++ - '0';
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (LONG_MAX);
	}
	return (num * sign);
}

int	stack_init(int argc, char **argv, t_stack *s, bool splitted)
{
	long	num;
	int		i;

	if (!s)
		return (-1);
	i = 0;
	if (splitted)
		--i;
	while (++i < argc)
	{
		num = custom_atol(argv[i]);
		if (num == LONG_MAX || is_duplicate_number(s, (int)num))
			return (-1);
		if (stack_push_bottom(s, (int)num) == -1)
			return (-1);
	}
	return (0);
}

t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = ft_calloc(INITIAL_CAPACITY, sizeof(t_element));
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->capacity = INITIAL_CAPACITY;
	stack->size = 0;
	return (stack);
}

void	stack_destroy(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->data)
		free(stack->data);
	free(stack);
}

int	stack_resize(t_stack *stack)
{
	t_element	*new_data;
	int			new_capacity;
	int			i;

	if (!stack)
		return (-1);
	new_capacity = stack->capacity * 2;
	new_data = ft_calloc(new_capacity, sizeof(t_element));
	if (!new_data)
		return (-1);
	i = 0;
	while (i < stack->size)
	{
		new_data[i] = stack->data[i];
		i++;
	}
	free(stack->data);
	stack->data = new_data;
	stack->capacity = new_capacity;
	return (0);
}

int	stack_push_bottom(t_stack *stack, int value)
{
	if (!stack)
		return (-1);
	if (stack->size >= stack->capacity)
		if (stack_resize(stack) == -1)
			return (-1);
	stack->data[stack->size].num = value;
	stack->size++;
	return (0);
}
