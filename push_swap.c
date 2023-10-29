/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:34:04 by alletond          #+#    #+#             */
/*   Updated: 2023/10/28 23:25:14 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_elements(t_stack **stack_a)
{
    int a, b, c;

    a = (*stack_a)->valeur;
    b = (*stack_a)->next->valeur;
    c = (*stack_a)->next->next->valeur;

    if (a > b && a < c)
        sa(stack_a, 1); // Swap a and b
    else if (a > c && b < c)
    {
        sa(stack_a, 1); // Swap a and b
        rra(stack_a, 1); // Rotate down
    }
    else if (a > b && b < c)
        sa(stack_a, 1); // Swap a and b
    else if (a > c && b > c)
	{
		sa(stack_a, 1);
        rra(stack_a, 1); // Rotate down
	}
	else if (a < c && b > a && b > c)
	{
		sa(stack_a, 1);
        ra(stack_a, 1);
	}
}






bool is_sorted(t_stack *stack) {
    while (stack && stack->next) {
        if (stack->valeur > stack->next->valeur) {
            return false;
        }
        stack = stack->next;
    }
    return true;
}

t_stack	*add_nbr(t_stack *list, int value)
{
	t_stack	*nouvelt_stack;

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

t_stack	*remlistelir_liste(int argc, char **argv, int *len)
{
	t_stack	*liste;
	int		valeur;

	liste = NULL;
	*len = 0;
	for (int i = 1; i < argc; i++)
	{
		valeur = atoi(argv[i]);
		liste = add_nbr(liste, valeur);
		(*len)++;
	}
	return (liste);
}

void	draw_list(t_stack *list)
{
	while (list)
	{
		printf("%d ", list->valeur);
		list = list->next;
	}
	printf("\n");
}
int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void solver2(t_game *nbr, t_stack **a, t_stack **b)
{	
		if (nbr->move_type == RA_RB)
		{
			solve_rr(nbr, a, b);
		}
		if (nbr->move_type == RRA_RB)
		{
			solve_rra_rb(nbr, a, b);
		}
		if (nbr->move_type == RA_RRB)
		{
			solve_ra_rrb(nbr, a, b);
		}
		if (nbr->move_type == RRA_RRB)
		{
			solve_rrr(nbr, a, b);
		}
		pb(a, b, 1);

}

void sort_stacks(t_stack **a, t_stack **b) 
{
	int nb;
	int sens_rot;
	int moves = 0;
	while (*b)
	{
		if ((*b)->valeur > find_max(*a))
		{
			sens_rot = rot_topA(*a, find_min(*a), &moves);
			while (moves > 0)
			{
				if (sens_rot == 1)
					ra(a,1);
				else
					rra(a, 1);
				moves--;
			}
			pa(a,b,1);
		}
		else
		{
			nb = find_closest_higher_number(*a, (*b)->valeur);
			sens_rot = rot_topA(*a, nb, &moves);
			while (moves > 0)
			{
				if (sens_rot == 1)
					ra(a,1);
				else
					rra(a, 1);
				moves--;
			}
			pa(a, b, 1);
		}
	}
}


void solver(t_stack **a, t_stack **b)
{
	t_game *res;

	int i = 0;
	
	pb(a, b, 1);
	pb(a, b, 1);
	while (stack_length(*a) != 3)
	{
		res = find_best_nb(*a, *b);
		solver2(res, a, b);
		i++;
	}
	sort_three_elements(a);
	sort_stacks(a, b);
	final_sort(a);
}

void final_sort(t_stack **a)
{
	int rot;
	int min;
	int moves;

	min = find_min(*a);
	rot = rot_topA(*a, min, &moves);
	while (moves > 0)
	{
		if (rot == 1)
			ra(a,1);
		else
			rra(a, 1);
		moves--;
	}

}

void	free_stacks(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}

	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}

void game(int argc, char **argv)
{
	t_stack	*liste;
	t_stack	*liste_b;
	int		len;

	liste = NULL;
	liste_b = NULL;
	len = 0;
	
	liste = remlistelir_liste(argc, argv, &len);
	if (len == 3)
	{
		printf("suu");
		sort_three_elements(&liste);
		draw_list(liste);
		return ;
	}
	if (len == 4)
	{
		sort_4_numbers(&liste, &liste_b);
		draw_list(liste);
		return ;
	}
	else if(len == 5)
	{
		sort_5_numbers(&liste, &liste_b);
		draw_list(liste);
		return ;
	}
	solver(&liste, &liste_b);
	draw_list(liste);
	free_stacks(liste, liste_b);
}
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (validate_args(argv, argc) != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	game(argc, argv);
	return (0);
}
