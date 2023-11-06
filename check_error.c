/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:13:42 by alletond          #+#    #+#             */
/*   Updated: 2023/11/02 15:09:11 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_int(char *str)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) || num > (long long)INT_MAX + 1)
			return (0);
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(char **argv, int len, char *str)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (ft_strcmp(argv[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	are_args_sorted(int argc, char **argv)
{
	int	i;
	int	current;
	int	next;

	i = 1;
	while (i < argc - 1)
	{
		current = ft_atoi(argv[i]);
		next = ft_atoi(argv[i + 1]);
		if (current > next)
		{
			if (argc == 3)
				return (3);
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	validate_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]) || has_duplicates(argv, i, argv[i])
			|| !is_valid_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
