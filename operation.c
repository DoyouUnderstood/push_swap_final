/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:43:29 by alletond          #+#    #+#             */
/*   Updated: 2023/10/28 21:13:19 by alletond         ###   ########.fr       */
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

t_stack	*createNode(int valeur)
{
	t_stack	*newNode;

	newNode = (t_stack *)malloc(sizeof(t_stack));
	newNode->valeur = valeur;
	newNode->prev = newNode->next = NULL;
	return (newNode);
}

void ra(t_stack** head, int print) {
       if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    t_stack* first = *head;
    t_stack* last = *head;

    while (last->next != NULL) {
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


void	rb(t_stack **stack_b, int print)
{
       if (*stack_b == NULL || (*stack_b)->next == NULL) {
        return;
    }

    t_stack* first = *stack_b;
    t_stack* last = *stack_b;

    while (last->next != NULL) {
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

void rrb(t_stack **stack_b, int print)
{
    t_stack *last;
    t_stack *second_last;

    if (!*stack_b || !(*stack_b)->next)
        return;

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


void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	if (print)
		ft_putstr("pa\n");
}

void pb(t_stack **a, t_stack **b, int print)
{
    t_stack *temp;

    if (!*a)
        return;
    temp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->prev = NULL;
    temp->next = *b;
    if (*b)
        (*b)->prev = temp;
    *b = temp;
    if (print)
        ft_putstr("pb\n");
}


void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr("rrr\n");
}

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

	closest_num = 600000; // Initialiser à une valeur suffisamment grande
	min_difference = 600000;
	current = stack;
	while (current)
	{
		if (current->valeur > target) // Changer la condition pour vérifier si la valeur est supérieure à la cible
		{
			difference = current->valeur - target; // Inverser la soustraction pour obtenir la différence correcte
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
