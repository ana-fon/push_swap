/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:59:38 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/12 14:59:38 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}				t_stack;

//PARSING
int		parsing(int ac, char **av, t_stack **a);
char	**copy_args(int ac, char **av, char **array);
int		check_and_count_arg(char **av);
int		check_numbers(int n, char **av, t_stack **a);
int		check_overflow(char **array, int size, t_stack **a);
int		check_duplicate(t_stack **a);
void	free_array(char **array, int n);
int		check_order(t_stack **a);
int		num_len(char *array);

//LISTS
void	list_init(t_stack **a, int num);
void	free_list(t_stack *a);
void	index_list(t_stack **a);
int		get_min(t_stack **stack);
int		min_pos(t_stack **stack, int min);

//SORTING
void	few_args(t_stack **a, t_stack **b, int size);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b, int size);
int		max_bits(int size);

//SORTING OPERATIONS
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	reverse_rotate_a(t_stack **a, int size);
void	rra(t_stack **a);
void	rrb(t_stack **b);

#endif