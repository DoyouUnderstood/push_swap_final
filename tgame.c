/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:42:03 by alletond          #+#    #+#             */
/*   Updated: 2023/10/28 20:55:17 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_game	*init_game(void)
{
	t_game *new_game;

	new_game = (t_game *)malloc(sizeof(t_game));
	if (!new_game)
		return (NULL); // Retourne NULL en cas d'échec d'allocation

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

void display_game(const t_game *game)
{
	printf("values: %d\n", game->values);
	printf("total_moves: %d\n", game->total_moves);
	printf("move_type: %u\n", game->move_type); // Vous devrez adapter cette ligne en fonction de la manière dont vous souhaitez afficher `move_type`
	printf("a_move_count: %d\n", game->a_move_count);
	printf("b_move_count: %d\n", game->b_move_count);
	printf("a_max: %d\n", game->a_max);
	printf("a_min: %d\n", game->a_min);
	printf("b_max: %d\n", game->b_max);
	printf("b_min: %d\n", game->b_min);
	printf("type_move_a: %d\n", game->type_move_a);
	printf("type_move_b: %d\n", game->type_move_b);
}