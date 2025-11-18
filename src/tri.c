/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 21:49:03 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*opti(char *sec)
{
	sec = replace(sec, "pb", "pa");
	sec = replace(sec, "pa", "pb");
	return (sec);
}

char	*algo_part2(t_stack *map, t_stack *b, t_bit *bit, char *sec)
{
	while (b->size > 0)
	{
		sec = strjoin_wish(sec, pa(map, b));
	}
	print_stack(map, b, -1);
	bit->index = bit->index + 1;
	if (bit->index < bit->max)
		sec = algo_part1(map, b, bit, sec);
	else
		free(bit);
	return (sec);
}

char	*algo_part1(t_stack *map, t_stack *b, t_bit *bit, char *sec)
{
	size_t	size;

	size = map->size;
	while (size > 0)
	{
		if (((map->tab[0] >> bit->index) & 1) == 0)
			sec = strjoin_wish(sec, pb(map, b));
		else
			sec = strjoin_wish(sec, ra(map));
		size--;
	}
	print_stack(map, b, bit->index);
	sec = algo_part2(map, b, bit, sec);
	return (sec);
}

char	*algo(t_stack *map, t_stack *b)
{
	t_bit	*bit;
	char	*sec;

	bit = init_bit(bit_max(map->size - 1), 0);
	sec = ft_calloc(1, sizeof(char));
	sec = algo_part1(map, b, bit, sec);
	ft_printf("\n%s", sec);
	sec = opti(sec);
	ft_printf("\n%s", sec);
	return (sec);
}
/**
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
}*/
