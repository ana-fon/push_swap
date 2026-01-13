/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:51:42 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/12 14:51:42 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (free_list(*a), 1);
}

char	**copy_args(int ac, char **av, char **array)
{
	int	i;

	i = 0;
	array = malloc (ac * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < ac - 1)
	{
		array[i] = ft_strdup(av[i + 1]);
		if (!array[i])
			return (free_array(array, i), NULL);
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	free_array(char **array, int n)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i <= n)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

int	num_len(char *array)
{
	int	counter;

	counter = 0;
	while (*array)
	{
		counter++;
		array++;
	}
	if (counter > 11)
		return (1);
	return (0);
}
