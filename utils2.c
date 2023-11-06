/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:51:18 by alletond          #+#    #+#             */
/*   Updated: 2023/11/02 14:41:37 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;

	max = -6000000;
	while (stack)
	{
		if (stack->valeur > max)
			max = stack->valeur;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = 6000000;
	while (stack)
	{
		if (stack->valeur < min)
			min = stack->valeur;
		stack = stack->next;
	}
	return (min);
}

int	find_closest_higher_number(t_stack *stack, int target)
{
	int		closest_num;
	int		min_difference;
	t_stack	*current;
	int		difference;

	closest_num = 600000;
	min_difference = 600000;
	current = stack;
	while (current)
	{
		if (current->valeur > target)
		{
			difference = current->valeur - target;
			if (difference < min_difference)
			{
				min_difference = difference;
				closest_num = current->valeur;
			}
		}
		current = current->next;
	}
	return (closest_num);
}

int	find_closest_lower_number(t_stack *stack, int target)
{
	int		closest_num;
	int		min_difference;
	t_stack	*current;
	int		difference;

	closest_num = -600000;
	min_difference = 600000;
	current = stack;
	while (current)
	{
		if (current->valeur < target)
		{
			difference = target - current->valeur;
			if (difference < min_difference)
			{
				min_difference = difference;
				closest_num = current->valeur;
			}
		}
		current = current->next;
	}
	return (closest_num);
}

void	rotate_and_push(t_stack **a, int target_val, t_stack **b)
{
	int	sens_rot;
	int	moves;

	sens_rot = rot_top_a(*a, target_val, &moves);
	while (moves-- > 0)
	{
		if (sens_rot == 1)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pa(a, b, 1);
}
