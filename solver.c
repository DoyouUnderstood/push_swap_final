/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:31:15 by alletond          #+#    #+#             */
/*   Updated: 2023/11/03 15:35:30 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_rra_rb(t_game *nbr, t_stack **a, t_stack **b)
{
	if (nbr->a_move_count > 0)
	{
		while (nbr->a_move_count != 0)
		{
			rra(a, 1);
			nbr->a_move_count--;
		}
	}
	if (nbr->b_move_count > 0)
	{
		while (nbr->b_move_count != 0)
		{
			rb(b, 1);
			nbr->b_move_count--;
		}
	}
}

void	solve_rr(t_game *nbr, t_stack **a, t_stack **b)
{
	while ((nbr->a_move_count != 0) && (nbr->b_move_count != 0))
	{
		rr(a, b, 1);
		nbr->a_move_count--;
		nbr->b_move_count--;
	}
	if (nbr->a_move_count > 0)
	{
		while (nbr->a_move_count != 0)
		{
			ra(a, 1);
			nbr->a_move_count--;
		}
	}
	while (nbr->b_move_count != 0)
	{
		rb(b, 1);
		nbr->b_move_count--;
	}
}

void	solve_ra_rrb(t_game *nbr, t_stack **a, t_stack **b)
{
	while (nbr->a_move_count != 0)
	{
		ra(a, 1);
		nbr->a_move_count--;
	}
	while (nbr->b_move_count != 0)
	{
		rrb(b, 1);
		nbr->b_move_count--;
	}
}

void	solve_rrr(t_game *nbr, t_stack **a, t_stack **b)
{
	while ((nbr->a_move_count != 0) && (nbr->b_move_count != 0))
	{
		rrr(a, b, 1);
		nbr->a_move_count--;
		nbr->b_move_count--;
	}
	while (nbr->a_move_count != 0)
	{
		rra(a, 1);
		nbr->a_move_count--;
	}
	while (nbr->b_move_count != 0)
	{
		rrb(b, 1);
		nbr->b_move_count--;
	}
}
