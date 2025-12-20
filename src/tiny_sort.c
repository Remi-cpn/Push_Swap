/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:41:43 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/20 13:58:50 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * This function sorts 3 or fewer numbers in the stack map.
 **/
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

/**
 * This function sorts for 4 or 5 numbers in the stack map.
 **/
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

/**
 * This function calls the corresponding algorithm for 3 and months or 4 and 
 * 5 values in the stack map.
 **/
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
