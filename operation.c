/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:43:29 by alletond          #+#    #+#             */
/*   Updated: 2023/11/06 17:02:32 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ra(t_stack **head, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (*head == NULL || (*head)->next == NULL)
	{
		return ;
	}
	first = *head;
	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (print)
		ft_putstr("ra\n");
}

void	solve_three_elements(t_stack **a)
{
	if (stack_length(*a) == 3)
	{
		sort_three_elements(a);
	}
}

void	solve_five_or_less_elements(t_stack **a, t_stack **b)
{
	if (stack_length(*a) <= 5)
	{
		solve_simple(a, b);
	}
}

void	max_to_top(t_stack **b)
{
	int	max;
	int	moves;
	int	rot;

	moves = 0;
	max = find_max(*b);
	rot = rot_top_a(*b, max, &moves);
	if (rot == 1)
		while (moves-- != 0)
			rb(b, 1);
	else if (rot == 0)
		while (moves-- != 0)
			rrb(b, 1);
}
