/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:51:59 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/12 14:51:59 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_init(t_stack **a, int num)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free(a);
		return ;
	}
	new_node->number = num;
	new_node->next = NULL;
	last = *a;
	if (*a == NULL)
	{
		*a = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void	free_list(t_stack *a)
{
	t_stack	*temp;

	while (a != NULL)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	free(a);
}

void	index_list(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;
	int		count;

	i = *a;
	while (i)
	{
		j = *a;
		count = 0;
		while (j)
		{
			if (i->number > j->number)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
}

int	get_min(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	min = (*stack)->number;
	temp = (*stack)->next;
	while (temp)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	return (min);
}

int	min_pos(t_stack **stack, int min)
{
	t_stack	*temp;
	int		counter;

	counter = 0;
	temp = *stack;
	while (temp->number != min)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}
