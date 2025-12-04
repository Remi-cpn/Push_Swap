/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:48:41 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/04 18:02:13 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*best_cost(int cost_1, int cost_2, int cost_3, int cost_4)
{
	int	*cost_best;

	cost_best = ft_calloc(3, sizeof(int));
	if (!cost_best)
		return (NULL);
	cost_best[0] = 1;
	cost_best[1] = cost_1;
	if (cost_2 < cost_best[1])
	{
		cost_best[0] = 2;
		cost_best[1] = cost_2;
	}
	if (cost_3 < cost_best[1])
	{
		cost_best[0] = 3;
		cost_best[1] = cost_3;
	}
	if (cost_4 < cost_best[1])
	{
		cost_best[0] = 4;
		cost_best[1] = cost_4;
	}
	return (cost_best);
}

int	pos_in_a(t_stack *map, int value)
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

static int	*best_move(t_stack *map, t_stack *b, int i)
{
	const int	pos_a = pos_in_a(map, b->tab[i]);
	int			pos_b;
	int			cost_1; // ra + rb;
	int			cost_2; // rra + rrb;
	int			cost_3; // ra + rrb;
	int			cost_4; // rra + rb;
	int			*cost_best;

	if (pos_a <= i)
		cost_1 = i;
	else
		cost_1 = pos_a;
	if (b->size == 1 || i == 0)
		pos_b = 0;
	else
		pos_b = b->size - i;
	if ((int)(map->size - pos_a) <= pos_b)
		cost_2 = pos_b;
	else
		cost_2 = (map->size - pos_a);
	cost_3 = pos_a + pos_b;
	cost_4 = (map->size - pos_a) + i;
	cost_best = best_cost(cost_1, cost_2, cost_3, cost_4);
	if (cost_best[0] == 1)
		cost_best[1] = pos_a + i;
	if (cost_best[0] == 2)
		cost_best[1] = (map->size - pos_a) + pos_b;
	return (cost_best);
}

int	*check_best_index(t_stack *map, t_stack *b)
{
	int	i;
	int	*curent_index;
	int	*best_index;

	ft_printf("\nRecherche du best Index de b  pour a:");
	best_index = ft_calloc(4, sizeof(int));
	if (!best_index)
		return (NULL);
	i = 0;
	while (i < (int)b->size)
	{
		curent_index = best_move(map, b, i);
		if (!curent_index)
			return (NULL);
		if (i == 0 || curent_index[1] < best_index[2])
		{
			best_index[0] = i;
			best_index[1] = curent_index[0];
			best_index[2] = curent_index[1];
		}
		free(curent_index);
		curent_index = NULL;
		i++;
	}
	ft_printf("\nMeilleur Index=%d Valeur=%d Senario=%d Moves=%d\n", best_index[0], b->tab[best_index[0]], best_index[1], best_index[2]);
	return (best_index);
}
