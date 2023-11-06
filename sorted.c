/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:32:56 by alletond          #+#    #+#             */
/*   Updated: 2023/11/02 14:58:59 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->valeur > stack->next->valeur)
		{
			return (false);
		}
		stack = stack->next;
	}
	return (true);
}

void	sort_three_elements(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->valeur;
	b = (*stack_a)->next->valeur;
	c = (*stack_a)->next->next->valeur;
	if (a > b && a < c)
		sa(stack_a, 1);
	else if (a < b && a > c && b > c && b > a)
		rra(stack_a, 1);
	else if (a > b && b < c)
		ra(stack_a, 1);
	else if (a > c && b > c)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a < c && b > a && b > c)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
}

int	find_index_of_value(t_stack *a, int value)
{
	int	index;

	index = 0;
	while (a)
	{
		if (a->valeur == value)
			return (index);
		a = a->next;
		index++;
	}
	return (-1);
}

void	sort_4_numbers(t_stack **a, t_stack **b)
{
	int	min_value;
	int	min_index;

	min_value = find_min(*a);
	min_index = find_index_of_value(*a, min_value);
	while (min_index-- > 0)
		ra(a, 1);
	pb(a, b, 1);
	sort_three_elements(a);
	pa(a, b, 1);
}

void	sort_5_numbers(t_stack **a, t_stack **b)
{
	int	min_index;
	int	min;

	min = find_min(*a);
	min_index = find_index_of_value(*a, min);
	while (min_index-- > 0)
		ra(a, 1);
	while (++min_index < stack_length(*a))
		rra(a, 1);
	pb(a, b, 1);
	sort_4_numbers(a, b);
	pa(a, b, 1);
}
