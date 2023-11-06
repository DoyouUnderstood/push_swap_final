/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:42:03 by alletond          #+#    #+#             */
/*   Updated: 2023/11/06 12:18:11 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	*init_game(void)
{
	t_game	*new_game;

	new_game = (t_game *)malloc(sizeof(t_game));
	if (!new_game)
		return (NULL);
	new_game->values = 0;
	new_game->total_moves = 600;
	new_game->move_type = 0;
	new_game->a_move_count = 0;
	new_game->b_move_count = 0;
	new_game->a_min = 0;
	new_game->a_max = 0;
	new_game->b_min = 0;
	new_game->b_max = 0;
	new_game->type_move_a = 0;
	new_game->type_move_b = 0;
	return (new_game);
}

char	**handle_str(char **argv)
{
	return (ft_split(argv[1], ' '));
}

t_stack	*remlistelir_liste(int argc, char **argv, int *len)
{
	t_stack	*liste;
	int		valeur;
	int		i;

	i = 1;
	liste = NULL;
	*len = 0;
	argc--;
	while (i <= argc)
	{
		valeur = ft_atoi(argv[argc]);
		liste = add_nbr(liste, valeur);
		(*len)++;
		argc--;
	}
	return (liste);
}

char	**process_single_argument(char *program_name, char **str)
{
	int		new_len;
	char	**new_argv;
	int		i;

	new_len = ft_strarr_len(str) + 1;
	new_argv = (char **)malloc(sizeof(char *) * (new_len + 1));
	if (!new_argv)
		return (NULL);
	new_argv[0] = program_name;
	i = 1;
	while (i < new_len)
	{
		new_argv[i] = str[i - 1];
		i++;
	}
	new_argv[new_len] = NULL;
	return (new_argv);
}

void	display_game(const t_game *game)
{
	printf("values: %d\n", game->values);
	printf("total_moves: %d\n", game->total_moves);
	printf("move_type: %u\n", game->move_type);
	printf("a_move_count: %d\n", game->a_move_count);
	printf("b_move_count: %d\n", game->b_move_count);
	printf("a_max: %d\n", game->a_max);
	printf("a_min: %d\n", game->a_min);
	printf("b_max: %d\n", game->b_max);
	printf("b_min: %d\n", game->b_min);
	printf("type_move_a: %d\n", game->type_move_a);
	printf("type_move_b: %d\n", game->type_move_b);
}
