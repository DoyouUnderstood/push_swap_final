/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_best_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:36:57 by alletond          #+#    #+#             */
/*   Updated: 2023/11/06 12:18:26 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_type(t_game *nbr)
{
	if (nbr->type_move_a == 1 && nbr->type_move_b == 1)
		nbr->move_type = RA_RB;
	else if (nbr->type_move_a == 0 && nbr->type_move_b == 1)
		nbr->move_type = RRA_RB;
	else if (nbr->type_move_a == 1 && nbr->type_move_b == 0)
		nbr->move_type = RA_RRB;
	else if (nbr->type_move_a == 0 && nbr->type_move_b == 0)
		nbr->move_type = RRA_RRB;
}

void total_mv(t_game *tmp)
{
	if (tmp->move_type == RA_RB || tmp->move_type == RRA_RRB)
	{
		if (tmp->a_move_count > tmp->b_move_count)
			tmp->total_moves = tmp->a_move_count;
		else
			tmp->total_moves = tmp->b_move_count;
	}
	else if (tmp->move_type == RA_RRB || tmp->move_type == RRA_RB)
		tmp->total_moves = tmp->a_move_count + tmp->b_move_count;
}

void who_s_best_nb(t_game *tmp, t_stack **a, t_stack **b, int value)
{
	tmp->values = value;
	tmp->type_move_a = rot_top_a(*a, tmp->values, &tmp->a_move_count);
	tmp->a_max = find_max(*a);
	tmp->a_min = find_min(*a);
	tmp->b_max = find_max(*b);
	tmp->b_min = find_min(*b);
	b_move_count(tmp, *b);
	move_type(tmp);
	total_mv(tmp);
	//display_game(tmp);
}

// fonction pour remplir t_game avec le meilleur nombre a push.
t_game	*find_best_nb(t_stack *a, t_stack *b)
{
	t_game	*tmp;
	t_game	*res;
	t_stack	*stack_tmp;

	tmp = NULL;
	stack_tmp = a;
	res = init_game();
	if (!res)
		return (NULL);
	while (stack_tmp)
	{
		tmp = init_game();
		if (!tmp)
		{
			free(res);
			res = NULL;
			return (NULL);
		}
		who_s_best_nb(tmp, &a, &b, stack_tmp->valeur);
		if (tmp->total_moves < res->total_moves)
		{
			free(res);
			res = tmp;
		}
		else
		{
			free(tmp);
			tmp = NULL;
		}
		stack_tmp = stack_tmp->next;
	}
	return (res);
}

t_stack	*add_nbr(t_stack *list, int value)
{
	t_stack *nouvelt_stack;

	nouvelt_stack = (t_stack *)malloc(sizeof(t_stack));
	{
		nouvelt_stack->valeur = value;
		nouvelt_stack->next = list;
		if (list)
		{
			list->prev = nouvelt_stack;
		}
		nouvelt_stack->prev = NULL;
		list = nouvelt_stack;
	}
	return (list);
}