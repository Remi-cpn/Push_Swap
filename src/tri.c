/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/15 17:44:21 by rcompain         ###   ########.fr       */
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
/*
char	*algo_rec(t_stack *map, t_stack *b, int bit)
{
	const int	nbr_bit = bit_max(map->size - 1);
	static int count = 0;
	static char *str = NULL;

	if (bit == nbr_bit)
	{
		str = ft_calloc(count, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	
}

void	call()
{

}
*/
int	algo(t_stack *map, t_stack *b)
{
	const int	nbr_bit = bit_max(map->size - 1);
	int			bit;
	size_t		size;
	int			count;

	bit = 0;
	count = 0;
	while (bit < nbr_bit)
	{
		size = map->size;
		while (size > 0)
		{
			if (((map->tab[0] >> bit) & 1) == 0)
				pb(map, b);
			else
				ra(map);
			size--;
			count++;
		}
		print_stack(map, b, bit);
		while (b->size > 0)
		{
			pa(map, b);
			count++;
		}
		print_stack(map, b, -1);
		bit++;
	}
	return (count);
}
