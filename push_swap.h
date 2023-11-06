/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:54:40 by alletond          #+#    #+#             */
/*   Updated: 2023/11/06 17:04:01 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

typedef struct s_stack
{
	int				valeur;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef enum e_move
{
	RA_RB,
	RA_RRB,
	RRA_RB,
	RRA_RRB
}					t_move;

typedef struct s_game
{
	int				values;
	int				total_moves;
	t_move			move_type;
	int				a_move_count;
	int				b_move_count;
	int				a_max;
	int				a_min;
	int				b_max;
	int				b_min;
	int				type_move_a;
	int				type_move_b;
}					t_game;

char				**process_single_argument(char *program_name, char **str);
int					stack_length(t_stack *stack);
int					find_position(t_stack *stack, int num);
int					rot_top_a(t_stack *a, int num, int *moves);
void				draw_list(t_stack *list);
t_stack				*add_nbr(t_stack *list, int value);
t_stack				*remlistelir_liste(int argc, char **argv, int *len);
void				ft_putstr(char *str);
int					ft_strarr_len(char **strarr);
void				ra(t_stack **liste_a, int print);
void				ss(t_stack **a, t_stack **b);
void				sa(t_stack **liste_a, int print);
void				rra(t_stack **liste_a, int print);
void				sa(t_stack **liste_a, int print);
void				rb(t_stack **liste_b, int print);
void				rrb(t_stack **liste_b, int print);
void				sb(t_stack **liste_b, int print);
void				ft_putstr(char *str);
void				rr(t_stack **liste_a, t_stack **liste_b, int print);
void				pb(t_stack **liste_a, t_stack **liste_b, int print);
void				pa(t_stack **liste_a, t_stack **liste_b, int print);
void				rrr(t_stack **a, t_stack **b, int print);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int					is_order(t_stack *liste);
t_game				*init_game(void);
int					are_args_sorted(int argc, char **argv);
char				**handle_str(char **argv);
void				display_game(const t_game *game);
t_game				*find_best_nb(t_stack *a, t_stack *b);
void				who_s_best_nb(t_game *tmp, t_stack **a, t_stack **b,
						int values);
int					find_closest_lower_number(t_stack *stack, int target);
int					find_closest_higher_number(t_stack *stack, int target);
void				b_move_count(t_game *tmp, t_stack *b);
void	max_to_top(t_stack **b);
// sorted

void				sort_5_numbers(t_stack **a, t_stack **b);
void				sort_4_numbers(t_stack **a, t_stack **b);
void				sort_three_elements(t_stack **stack_a);
void				sort_stacks(t_stack **a, t_stack **b);
void				final_sort(t_stack **a);

// solver
void	solve_simple(t_stack **a, t_stack **b);
void				solve_rr(t_game *nbr, t_stack **a, t_stack **b);
void				solve_rra_rb(t_game *nbr, t_stack **a, t_stack **b);
void				solve_ra_rrb(t_game *nbr, t_stack **a, t_stack **b);
void				solve_rrr(t_game *nbr, t_stack **a, t_stack **b);
void				solver(t_stack **a, t_stack **b);
void				solve_three_elements(t_stack **a);
void				solve_five_or_less_elements(t_stack **a, t_stack **b);
// erreur

int					validate_args(char **argv, int argc);
int					is_sorted2(char **arr, int argc);
int					has_duplicates(char **argv, int len, char *str);
int					is_numeric(char *str);
int					is_valid_int(char *str);
void				rotate_and_push(t_stack **a, int target_val, t_stack **b);
int					check_and_validate(int *argc, char ***argv, char **str);

// free
void				free_stacks(t_stack *a, t_stack *b);
void				free_str_array(char **str);

// checker

char				*get_next_line(int fd);
int					is_order(t_stack *liste);
bool				process_lines(t_stack **a, t_stack **b, int *op_count);
bool				process_instr(t_stack **a, t_stack **b, char *instr,
						int *op_count);
void				print_result_msg(t_stack *a, t_stack *b, int op_count);

#endif
