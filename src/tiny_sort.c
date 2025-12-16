/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:41:43 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/16 17:07:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	sort_just_map(t_stack *map, t_list **lst, int flag)
{
	while (stack_sorted(map) == FALSE && flag == 0)
	{
		if (map->tab[0] > map->tab[1] && map->tab[0] > map->tab[map->size - 1])
			flag = new_cmd(lst, map, NULL, ra);
		else if (map->tab[0] > map->tab[1])
			flag = new_cmd(lst, map, NULL, sa);
		else
			flag = new_cmd(lst, map, NULL, rra);
	}
	return (flag);
}

static int	sort_use_b(t_stack *map, t_stack *b, t_list **lst, int flag)
{
	flag = new_cmd(lst, map, b, pb);
	if (flag == 0)
		flag = new_cmd(lst, map, b, pb);
	if (flag == 0)
		flag = sort_just_map(map, lst, flag);
	flag = push_best_to_a(map, b, lst, flag);
	return (flag);
}

int	tiny_sort(t_stack *map, t_stack *b, t_list **lst)
{
	int	flag;

	flag = 0;
	if (map->size < 4)
		flag = sort_just_map(map, lst, flag);
	else
		flag = sort_use_b(map, b, lst, flag);
	return (flag);
}
