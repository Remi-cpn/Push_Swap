/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/06 15:46:05 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	new_cmd(t_list **lst, t_stack *stack1, t_stack *stack2,
				char *(*cmd)(t_stack *, t_stack *))
{
	char		*dup;
	const char	*str;
	t_list		*new;

	if (!stack2)
		str = (const char *)cmd(stack1, NULL);
	else
		str = (const char *)cmd(stack1, stack2);
	dup = ft_strdup(str);
	if (!dup)
		return (-1);
	new = ft_lstnew(dup);
	if (!new)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

static int	rotate_min_to_top(t_stack *map, t_list **lst, int flag)
{
	if (flag == -1)
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

static int	push_best_to_a(t_stack *map, t_stack *b, t_list **lst, int flag)
{
	int			move;
	const int	*cost_best = check_best_index(map, b);
	const int	value = b->tab[cost_best[0]];

	if (!cost_best || flag == -1)
		return (-1);
	move = cost_best[2];
	while ((cost_best[1] == 1 || cost_best[1] == 4) && b->tab[0] != value
		&& flag == 0)
	{
		flag = new_cmd(lst, b, NULL, rb);
		move--;
	}
	while ((cost_best[1] == 2 || cost_best[1] == 3) && b->tab[0] != value
		&& flag == 0)
	{
		flag = new_cmd(lst, b, NULL, rrb);
		move--;
	}
	while ((cost_best[1] == 1 || cost_best[1] == 3) && move-- != 0 && flag == 0)
		flag = new_cmd(lst, map, NULL, ra);
	while ((cost_best[1] == 2 || cost_best[1] == 4) && move-- != 0 && flag == 0)
		flag = new_cmd(lst, map, NULL, rra);
	free((int *)cost_best);
	return (flag);
}

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
		if (map->tab[0] >= (chunk - n) && map->tab[0] <= chunk)
			flag = new_cmd(lst, map, b, pb);
		else
			flag = new_cmd(lst, map, NULL, ra);
		size--;
	}
	flag = push_with_chunk_to_b(map, b, lst, n);
	return (flag);
}

/**
 * Cet algo tri la stack a (ici map) par ordre croissant en utilisant la stack
 * b. Une premiere phase en pushant les element de a dans b par un systeme 
 * default chunks. Puis il va push les elements de b vers a en un minimum de 
 * couts. Pour finir il va faire tourner les elements de a pour mettre le min 
 * en haut.
 */
t_list	*algo_sort(t_stack *map, t_stack *b, int flag)
{
	t_list		*lst;
	int			n;

	if (map->size < 4)
		n = 4;
	else
		n = map->size / 4;
	lst = NULL;
	print_stack(map, b);
	flag = push_with_chunk_to_b(map, b, &lst, n);
	print_stack(map, b);
	while (b->size > 0 && flag == 0)
	{
		flag = push_best_to_a(map, b, &lst, flag);
		flag = new_cmd(&lst, map, b, pa);
		print_stack(map, b);
	}
	if (flag == -1 || rotate_min_to_top(map, &lst, flag) == -1)
		return (NULL);
	print_stack(map, b);
	return (lst);
}
