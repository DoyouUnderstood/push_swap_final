/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:01:51 by alletond          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:23 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver2(t_game *nbr, t_stack **a, t_stack **b)
{
	if (nbr->move_type == RA_RB)
		solve_rr(nbr, a, b);
	if (nbr->move_type == RRA_RB)
		solve_rra_rb(nbr, a, b);
	if (nbr->move_type == RA_RRB)
		solve_ra_rrb(nbr, a, b);
	if (nbr->move_type == RRA_RRB)
		solve_rrr(nbr, a, b);
	pb(a, b, 1);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	nb;

	max_to_top(b);
	while (*b)
	{
		if ((*b)->valeur > find_max(*a))
			rotate_and_push(a, find_min(*a), b);
		else
		{
			nb = find_closest_higher_number(*a, (*b)->valeur);
			rotate_and_push(a, nb, b);
		}
	}
}

void	solve_simple(t_stack **a, t_stack **b)
{
	int	sens;
	int	max;
	int	moves;

	moves = 0;
	if (stack_length(*a) == 3)
		sort_three_elements(a);
	else if (stack_length(*a) > 3)
	{
		while (stack_length(*a) != 3)
		{
			max = find_min(*a);
			sens = rot_top_a(*a, max, &moves);
			if (sens == 1)
				while (moves-- != 0)
					ra(a, 1);
			else if (sens == 0)
				while (moves-- != 0)
					rra(a, 1);
			pb(a, b, 1);
		}
		sort_three_elements(a);
	}
	while (*b)
		pa(a, b, 1);
}

void	solver(t_stack **a, t_stack **b)
{
	t_game	*res;
	int		i;

	i = 0;
	solve_three_elements(a);
	solve_five_or_less_elements(a, b);
	if (stack_length(*a) > 5)
	{
		pb(a, b, 1);
		pb(a, b, 1);
		while (stack_length(*a) != 3)
		{
			res = find_best_nb(*a, *b);
			solver2(res, a, b);
			free(res);
			res = NULL;
			i++;
		}
		sort_three_elements(a);
		sort_stacks(a, b);
		final_sort(a);
	}
}

void	final_sort(t_stack **a)
{
	int	rot;
	int	min;
	int	moves;

	min = find_min(*a);
	rot = rot_top_a(*a, min, &moves);
	while (moves > 0)
	{
		if (rot == 1)
			ra(a, 1);
		else
			rra(a, 1);
		moves--;
	}
}
