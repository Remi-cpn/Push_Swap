/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/14 18:48:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	bit_max(size_t index_max)
{
	static int	nbr_bit = 0;

	if (index_max == 0)
		return (0);
	bit_max(index_max / 2);
	nbr_bit++;
	return (nbr_bit);
}

int	algo(t_stack *map, t_stack *b)
{
	const int	nbr_bit = bit_max(map->size - 1);
	size_t		i;
	int			bit;
	size_t		size;
	int			count;

	bit = 0;
	count = 0;
	while (bit < nbr_bit)
	{
		i = 0;
		size = map->size;
		while (i < size)
		{
			if (((map->tab[0] >> bit) & 1) == 0)
				pb(map, b);
			else
				ra(map);
			i++;
			count++;
		}
		while (b->size > 0)
		{
			pa(map, b);
			count++;
		}
		bit++;
	}
	return (count);
}
