/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:09:07 by alletond          #+#    #+#             */
/*   Updated: 2023/11/06 17:01:29 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	find_position(t_stack *stack, int num)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->valeur == num)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	rot_top_a(t_stack *a, int num, int *moves)
{
	int	pos_a;
	int	len_a;

	pos_a = find_position(a, num);
	len_a = stack_length(a);
	if (pos_a <= len_a / 2)
	{
		*moves = pos_a;
		return (1);
	}
	else
	{
		*moves = len_a - pos_a;
		return (0);
	}
}

void	b_move_count(t_game *tmp, t_stack *b)
{
	int	min;

	if (tmp->values > tmp->b_max || tmp->values < tmp->b_min)
	{
		if (rot_top_a(b, tmp->b_max, &tmp->b_move_count) == 0)
			tmp->type_move_b = 0;
		else
			tmp->type_move_b = 1;
	}
	else
	{
		min = find_closest_lower_number(b, tmp->values);
		if (rot_top_a(b, min, &tmp->b_move_count) == 0)
			tmp->type_move_b = 0;
		else
			tmp->type_move_b = 1;
	}
}

int	is_order(t_stack *liste)
{
	while (liste && liste->next)
	{
		if (liste->valeur > liste->next->valeur)
			return (0);
		liste = liste->next;
	}
	return (1);
}
