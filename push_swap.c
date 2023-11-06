/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:34:04 by alletond          #+#    #+#             */
/*   Updated: 2023/11/02 18:15:04 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	game(int argc, char **argv)
{
	t_stack	*liste;
	t_stack	*liste_b;
	int		len;

	if (are_args_sorted(argc, argv) == 3)
	{
		ft_putstr("sa");
		return ;
	}
	else if (are_args_sorted(argc, argv) == 1)
	{
		return ;
	}
	liste = NULL;
	liste_b = NULL;
	len = 0;
	liste = remlistelir_liste(argc, argv, &len);
	solver(&liste, &liste_b);
	free_stacks(liste, liste_b);
}

int	main(int argc, char **argv)
{
	char	**str;
	char	**new_argv;

	str = NULL;
	new_argv = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		str = handle_str(argv);
		new_argv = process_single_argument(argv[0], str);
		argc = ft_strarr_len(str) + 1;
		argv = new_argv;
	}
	if (!check_and_validate(&argc, &argv, str))
		return (0);
	game(argc, argv);
	if (str)
		free_str_array(str);
	if (new_argv)
		free(new_argv);
	return (0);
}
