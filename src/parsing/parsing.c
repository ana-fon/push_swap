/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:51:49 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/12 14:51:49 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;

	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number == j->number)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	check_overflow(char **array, int size, t_stack **a)
{
	long	num;
	int		i;

	i = 0;
	while (i < size)
	{
		num = ft_atol(array[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_printf("Error\n"),
				free_array(array, size), free_list(*a), 0);
		list_init(a, (int)num);
		i++;
	}
	if (check_duplicate(a))
		return (ft_printf("Error\n"),
			free_array(array, size), free_list(*a), 0);
	free_array(array, size);
	return (size);
}

int	check_number(int n, char **av, t_stack **a)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (av[i][j])
		{
			if (((av[i][j] == '-') || (av[i][j] == '+'))
				&& ft_isdigit(av[i][j + 1]))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				free_array(av, n);
				return (ft_printf("Error\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (check_overflow(av, n, a));
}

int	check_and_count_arg(char **av)
{
	int		i;
	int		args;

	i = 0;
	args = 0;
	while (av[1][i])
	{
		while (av[1][i] == ' ')
			i++;
		if ((ft_isdigit(av[1][i]) || av[1][i] == '-'
			|| av[1][i] == '+') && (av[1][i]))
			args++;
		else if (!ft_isdigit(av[1][i]) && av[1][i] != ' ' && av[1][i] != '\0')
			return (ft_printf("Error\n"), 0);
		while (av[1][i] != ' ' && av[1][i])
			i++;
	}
	return (args);
}

int	parsing(int ac, char **av, t_stack **a)
{
	char	**array;
	int		arg_counter;

	arg_counter = 0;
	array = NULL;
	if (ac == 2 && av[1][0])
	{
		arg_counter = check_and_count_arg(av);
		if (arg_counter > 0)
			array = ft_split(av[1], ' ');
		return (check_number(arg_counter, array, a));
	}
	if (ac > 2)
	{
		array = copy_args(ac, av, array);
		return (check_number(ac - 1, array, a));
	}
	return (0);
}
