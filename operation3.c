/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:59:21 by alletond          #+#    #+#             */
/*   Updated: 2023/11/01 15:00:28 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **stack_b, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return ;
	}
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (print)
		ft_putstr("rb\n");
}

void	sa(t_stack **stack_a, int print)
{
	int	temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->valeur;
	(*stack_a)->valeur = (*stack_a)->next->valeur;
	(*stack_a)->next->valeur = temp;
	if (print)
		ft_putstr("sa\n");
}

void	sb(t_stack **stack_b, int print)
{
	int	temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->valeur;
	(*stack_b)->valeur = (*stack_b)->next->valeur;
	(*stack_b)->next->valeur = temp;
	if (print)
		ft_putstr("sb\n");
}

void	rra(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack_a;
	(*stack_a)->prev = temp;
	*stack_a = temp;
	if (print)
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_b;
	(*stack_b)->prev = last;
	last->prev = NULL;
	*stack_b = last;
	if (print)
		ft_putstr("rrb\n");
}
