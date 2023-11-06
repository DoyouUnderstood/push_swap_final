/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:56:29 by alletond          #+#    #+#             */
/*   Updated: 2023/11/02 15:01:51 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_validate(int *argc, char ***argv, char **str)
{
	if (validate_args(*argv, *argc) != 1)
	{
		write(1, "Error\n", 6);
		free_str_array(str);
		return (0);
	}
	return (1);
}

int	ft_strarr_len(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i])
		i++;
	return (i);
}

void	free_str_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
