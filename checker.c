/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:17:47 by alletond          #+#    #+#             */
/*   Updated: 2023/11/03 15:36:01 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	process_instr(t_stack **a, t_stack **b, char *instr, int *op_count)
{
	bool	result;

	result = true;
	if (!ft_strncmp(instr, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(instr, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(instr, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(instr, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(instr, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(instr, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(instr, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(instr, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(instr, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(instr, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(instr, "rrr\n", 4))
		rrr(a, b, 0);
	else
		return (false);
	if (result)
		(*op_count)++;
	return (result);
}

bool	process_lines(t_stack **a, t_stack **b, int *op_count)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!process_instr(a, b, line, op_count))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(0);
	}
	return (true);
}

void	print_result_msg(t_stack *a, t_stack *b, int op_count)
{
	if (is_order(a) && stack_length(b) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr_fd("KO\n", 1);
	ft_putstr_fd("Nombre d'opérations : ", 1);
	ft_putnbr_fd(op_count, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	int		nb_op;

	nb_op = 0;
	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	a = remlistelir_liste(argc, argv, &len);
	if (!process_lines(&a, &b, &nb_op))
	{
		write(1, "Error\n", 6);
		free_stacks(a, b);
		return (1);
	}
	print_result_msg(a, b, nb_op);
	free_stacks(a, b);
	return (0);
}
