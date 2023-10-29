/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_best_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:36:57 by alletond          #+#    #+#             */
/*   Updated: 2023/10/28 20:13:49 by alletond         ###   ########.fr       */
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

int	rot_topA(t_stack *a, int num, int *moves)
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

t_game	*b_move_count(t_game *tmp, t_stack *b)
{
	int	min;

	if (tmp->values > tmp->b_max || tmp->values < tmp->b_min)
	{
		if (rot_topA(b, tmp->b_max, &tmp->b_move_count) == 0)
			tmp->type_move_b = 0;
		else
			tmp->type_move_b = 1;
	}
	else
	{
		min = find_closest_lower_number(b, tmp->values);
		if (rot_topA(b, min, &tmp->b_move_count) == 0)
			tmp->type_move_b = 0;
		else
			tmp->type_move_b = 1;
	}
	return (tmp);
}

t_game *move_type(t_game *nbr)
{
	if (nbr->type_move_a == 1 && nbr->type_move_b == 1)
		nbr->move_type = RA_RB;
	else if (nbr->type_move_a == 0 && nbr->type_move_b == 1)
		nbr->move_type = RRA_RB;
	else if (nbr->type_move_a == 1 && nbr->type_move_b == 0)
		nbr->move_type = RA_RRB;
	else if(nbr->type_move_a == 0 && nbr->type_move_b == 0)
		nbr->move_type = RRA_RRB;
	return (nbr);
}

t_game	*total_mv(t_game *tmp)
{
		if (tmp->move_type == RA_RB || tmp->move_type == RRA_RRB) {
		// Les mouvements vont dans le même sens
		if (tmp->a_move_count > tmp->b_move_count) {
			tmp->total_moves = tmp->a_move_count;
		} else {
			tmp->total_moves = tmp->b_move_count;
		}
	} else if (tmp->move_type == RA_RRB || tmp->move_type == RRA_RB) {
		// Les mouvements vont dans des directions opposées
		tmp->total_moves = tmp->a_move_count + tmp->b_move_count;
	}
	return (tmp);
}
t_game	*who_s_best_nb(t_stack **a, t_stack **b, int values)
{
	t_game	*tmp;

	(void)b;
	tmp = init_game();
	tmp->values = values;
	tmp->type_move_a = rot_topA(*a, tmp->values, &tmp->a_move_count);
	tmp->a_max = find_max(*a);
	tmp->a_min = find_min(*a);
	tmp->b_max = find_max(*b);
	tmp->b_min = find_min(*b);
	tmp = b_move_count(tmp, *b);
	tmp = move_type(tmp);
	tmp = total_mv(tmp);
	return (tmp);
}

// fonction pour remplir t_game avec le meilleur nombre a push.
t_game	*find_best_nb(t_stack *a, t_stack *b)
{
	t_game	*tmp;
	t_game	*res;
	t_stack	*stack_tmp;

	stack_tmp = a;
	tmp = init_game();
	res = init_game();
	if (!tmp || !res)
		return (NULL);
	while (stack_tmp)
	{
		tmp = who_s_best_nb(&a, &b, stack_tmp->valeur);
		if (tmp->total_moves < res->total_moves)
		{
			free(res);
			res = tmp;
		}
		else
			free(tmp);
		stack_tmp = stack_tmp->next;
	}

	return (res);
}
