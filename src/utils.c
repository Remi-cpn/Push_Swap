/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:26:36 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/04 17:41:28 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mapping(t_stack *a, t_stack *map)
{
	int	i;
	int	j;

	if (a->size == 0)
		return ;
	i = 0;
	map->tab[0] = 0;
	while (i < (int)a->size - 1)
	{
		i++;
		map->tab[i] = 0;
		j = 0;
		while (j < i)
		{
			if (a->tab[i] > a->tab[j])
				map->tab[i]++;
			else
				map->tab[j]++;
			j++;
		}
	}
}
