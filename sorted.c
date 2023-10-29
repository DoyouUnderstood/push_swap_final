#include "push_swap.h"

int	find_index_of_value(t_stack *a, int value)
{
	int	index = 0;
	while (a)
	{
		if (a->valeur == value)
			return index;
		a = a->next;
		index++;
	}
	return -1; // Retourne -1 si la valeur n'est pas trouvée (ne devrait pas se produire)
}

void	sort_4_numbers(t_stack **a, t_stack **b)
{
	int	min_value;
	int	min_index;

	min_value = find_min(*a);
	min_index = find_index_of_value(*a, min_value);

	while (min_index-- > 0)
		ra(a, 1);
	pb(a, b, 1);
	sort_three_elements(a);
	pa(a, b, 1);
}

void	sort_5_numbers(t_stack **a, t_stack **b)
{
	int	min_index;
    int min;

    min = find_min(*a);
	min_index = find_index_of_value(*a, min);
	while (min_index-- > 0)
		ra(a, 1);
	while (++min_index < stack_length(*a))
		rra(a, 1);
	pb(a, b, 1);
	sort_4_numbers(a, b);
	pa(a, b, 1);
}

