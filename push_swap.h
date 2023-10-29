#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				type_move_a; // 1 ra 
	int				type_move_b; //
}					t_game;

int					stack_length(t_stack *stack);
int					find_position(t_stack *stack, int num);
int					rot_topA(t_stack *a, int num, int *moves);
void				draw_list(t_stack *list);
t_stack				*add_nbr(t_stack *list, int value);
t_stack				*remlistelir_liste(int argc, char **argv, int *len);
void				ft_putstr(char *str);
t_stack				*createNode(int valeur);
void				ra(t_stack **liste_a, int print);
void				sa(t_stack **liste_a, int print);
void				rra(t_stack **liste_a, int print);
void				sa(t_stack **liste_a, int print);
void				rb(t_stack **liste_b, int print);
void				rrb(t_stack **liste_b, int print);
void				sb(t_stack **liste_b, int print);
void				ft_putstr(char *str);
void				rr(t_stack **liste_a, t_stack **liste_b);
void				pb(t_stack **liste_a, t_stack **liste_b, int print);
void				pa(t_stack **liste_a, t_stack **liste_b, int print);
void	rrr(t_stack **a, t_stack **b);
int					find_max(t_stack *stack);
int					find_min(t_stack *stack);
int     			is_order(t_stack *liste);
t_game				*init_game(void);

void				display_game(const t_game *game);
t_game				*find_best_nb(t_stack *a, t_stack *b);
t_game				*who_s_best_nb(t_stack **a, t_stack **b, int values);
int					find_closest_lower_number(t_stack *stack, int target);
int	find_closest_higher_number(t_stack *stack, int target);

// sorted

void	sort_5_numbers(t_stack **a, t_stack **b);
void	sort_4_numbers(t_stack **a, t_stack **b);
void sort_three_elements(t_stack **stack_a);

//solver 
void solve_rr(t_game *nbr, t_stack **a, t_stack **b);
void solve_rra_rb(t_game *nbr, t_stack **a, t_stack **b);
void solve_ra_rrb(t_game *nbr, t_stack **a, t_stack **b);
void solve_rrr(t_game *nbr, t_stack **a, t_stack **b);
void final_sort(t_stack **a);

// erreur

int	validate_args(char **argv, int argc);
int	is_sorted2(char **arr, int argc);
int	has_duplicates(char **argv, int len, char *str);
int	is_numeric(char *str);
int	is_valid_int(char *str);

#endif
