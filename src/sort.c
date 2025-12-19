/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/19 14:41:01 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * This function rotates the stack to put the minimum at the top.
 **/
static int	rotate_min_to_top(t_stack *map, t_list **lst, int flag)
{
	if (flag == ERROR)
		return (flag);
	if (map->size <= 1)
		return (0);
	if (map->tab[0] > (int)map->size / 2)
	{
		while (map->tab[0] != 0 && flag == 0)
			flag = new_cmd(lst, map, NULL, ra);
	}
	else
	{
		while (map->tab[0] != 0 && flag == 0)
			flag = new_cmd(lst, map, NULL, rra);
	}
	return (flag);
}

/**
 * This function pushes a value from stack b to the stack map 
 * at its sorted position. It chooses the value with the lowest 
 * movement cost.
 **/
int	push_best_to_a(t_stack *map, t_stack *b, t_list **lst, int flag)
{
	int			mv;
	const int	*best = check_best_index(map, b);
	const int	value = b->tab[best[0]];

	if (!best || flag == ERROR)
		return (ERROR);
	mv = best[2];
	while ((best[1] == RA_RB || best[1] == RRA_RB)
		&& b->tab[0] != value && flag == 0)
	{
		flag = new_cmd(lst, b, NULL, rb);
		mv--;
	}
	while ((best[1] == RRA_RRB || best[1] == RA_RRB)
		&& b->tab[0] != value && flag == 0)
	{
		flag = new_cmd(lst, b, NULL, rrb);
		mv--;
	}
	while ((best[1] == RA_RB || best[1] == RA_RRB) && mv-- != 0 && flag == 0)
		flag = new_cmd(lst, map, NULL, ra);
	while ((best[1] == RRA_RRB || best[1] == RRA_RB) && mv-- != 0 && flag == 0)
		flag = new_cmd(lst, map, NULL, rra);
	free((int *)best);
	return (flag);
}

/**
 * This function pushes the values from the stack map into a chunk system.
 **/
static int	push_with_chunk_to_b(t_stack *map, t_stack *b, t_list **lst, int n)
{
	static int	chunk = -1;
	size_t		size;
	int			flag;

	flag = 0;
	chunk += n;
	if (map->size == 0)
		return (0);
	size = map->size;
	while (size > 0 && flag == 0)
	{
		if (map->tab[0] <= chunk)
		{
			flag = new_cmd(lst, map, b, pb);
			if (b->tab[0] <= chunk - (n / 2))
				flag = new_cmd(lst, b, NULL, rb);
		}
		else
			flag = new_cmd(lst, map, NULL, ra);
		size--;
	}
	flag = push_with_chunk_to_b(map, b, lst, n);
	return (flag);
}

/**
 * This function checks if the number of values is less than 6 in order 
 * to execute an optimized algorithm. If not, it executes the main algorithm.
 **/
t_list	*algo_sort(t_stack *map, t_stack *b, int flag)
{
	t_list		*lst;

	if (stack_sorted(map) == TRUE)
		return (NULL);
	lst = NULL;
	if (map->size <= 5)
		flag = tiny_sort(map, b, &lst);
	else
		flag = push_with_chunk_to_b(map, b, &lst, map->size / NBR_CHUNK);
	while (b->size > 0 && flag == 0)
	{
		flag = push_best_to_a(map, b, &lst, flag);
		flag = new_cmd(&lst, map, b, pa);
	}
	if (flag == ERROR || rotate_min_to_top(map, &lst, flag) == ERROR)
		return (NULL);
	return (lst);
}
