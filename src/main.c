/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:52:18 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/12 14:52:18 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		arg_counter;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(0);
	arg_counter = parsing(ac, av, &a);
	if (!arg_counter)
		exit(1);
	if (check_order(&a))
		exit(0);
	if (arg_counter <= 5)
		few_args(&a, &b, arg_counter);
	if (arg_counter > 5)
		radix_sort(&a, &b, arg_counter);
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	return (0);
}
