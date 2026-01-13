/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anisabel <anisabel@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:52:05 by anisabel          #+#    #+#             */
/*   Updated: 2026/01/12 14:52:05 by anisabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	t_stack	*temp;
	int		max;
	int		i;
	int		j;

	i = -1;
	index_list(a);
	max = max_bits(size - 1);
	while (++i < max)
	{
		j = 0;
		while (j < size)
		{
			temp = *a;
			if (((temp->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
	}
}

int	max_bits(int size)
{
	int		max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
