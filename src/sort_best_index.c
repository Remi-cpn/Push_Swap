/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_best_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:48:41 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/08 16:51:10 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*best_cost(int cost_ra_rb, int cost_rra_rrb, int cost_ra_rrb,
					int cost_rra_rb)
{
	int	*cost_best;

	cost_best = ft_calloc(3, sizeof(int));
	if (!cost_best)
		return (NULL);
	cost_best[0] = RA_RB;
	cost_best[1] = cost_ra_rb;
	if (cost_rra_rrb < cost_best[1])
	{
		cost_best[0] = RRA_RRB;
		cost_best[1] = cost_rra_rrb;
	}
	if (cost_ra_rrb < cost_best[1])
	{
		cost_best[0] = RA_RRB;
		cost_best[1] = cost_ra_rrb;
	}
	if (cost_rra_rb < cost_best[1])
	{
		cost_best[0] = RRA_RB;
		cost_best[1] = cost_rra_rb;
	}
	return (cost_best);
}

static int	pos_in_a(t_stack *map, int value)
{
	int	i;
	int	i_max;
	int	i_min;

	if (map->size == 0)
		return (0);
	i = 0;
	i_max = 0;
	i_min = 0;
	while (++i < (int)map->size)
	{
		if (map->tab[i] > map->tab[i_max])
			i_max = i;
		if (map->tab[i] < map->tab[i_min])
			i_min = i;
	}
	if (value < map->tab[i_min] || value > map->tab[i_max])
		return (i_max + 1);
	i = -1;
	while (++i < (int)map->size - 1)
	{
		if (map->tab[i] < value && map->tab[i + 1] > value)
			return (i + 1);
	}
	return (i + 1);
}

static int	cost_calc(int value1, int value2)
{
	int	result;

	if (value1 <= value2)
		result = value2;
	else
		result = value1;
	return (result);
}

static int	*best_move(t_stack *map, t_stack *b, int i)
{
	const int	pos_a = pos_in_a(map, b->tab[i]);
	int			pos_b;
	t_cost		c;

	if (b->size == 1 || i == 0)
		pos_b = 0;
	else
		pos_b = b->size - i;
	c.ra_rb = cost_calc(pos_a, i);
	c.rra_rrb = cost_calc((int)(map->size - pos_a), pos_b);
	c.ra_rrb = pos_a + pos_b;
	c.rra_rb = (map->size - pos_a) + i;
	c.best = best_cost(c.ra_rb, c.rra_rrb, c.ra_rrb, c.rra_rb);
	if (!c.best)
		return (NULL);
	if (c.best[0] == RA_RB)
		c.best[1] = pos_a + i;
	if (c.best[0] == RRA_RRB)
		c.best[1] = (map->size - pos_a) + pos_b;
	return (c.best);
}

int	*check_best_index(t_stack *map, t_stack *b)
{
	int		i;
	t_index	index;

	index.best = ft_calloc(4, sizeof(int));
	if (!index.best)
		return (NULL);
	i = 0;
	while (i < (int)b->size)
	{
		index.curent = best_move(map, b, i);
		if (!index.curent)
			return (NULL);
		if (i == 0 || index.curent[1] < index.best[2])
		{
			index.best[0] = i;
			index.best[1] = index.curent[0];
			index.best[2] = index.curent[1];
		}
		free(index.curent);
		index.curent = NULL;
		i++;
	}
	return (index.best);
}
