/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/04 17:48:33 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_min_to_top(t_stack *map, t_list **lst)
{
	if (map->size <= 1)
		return ;
	if (map->tab[0] > (int)map->size / 2)
	{
		while (map->tab[0] != 0)
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(ra(map))));
	}
	else
	{
		while (map->tab[0] != 0)
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(rra(map))));
	}
}

static void	push_best_to_a(t_stack *map, t_stack *b, t_list **lst)
{
	int			move;
	const int	*cost_best = check_best_index(map, b);
	const int	value = b->tab[cost_best[0]];

	if (!cost_best)
		return ;
	move = cost_best[2];
	while ((cost_best[1] == 1 || cost_best[1] == 4) && b->tab[0] != value)
	{
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(rb(b))));
		move--;
	}
	while ((cost_best[1] == 2 || cost_best[1] == 3) && b->tab[0] != value)
	{
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(rrb(b))));
		move--;
	}
	while ((cost_best[1] == 1 || cost_best[1] == 3) && move-- != 0)
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(ra(map))));
	while ((cost_best[1] == 2 || cost_best[1] == 4) && move-- != 0)
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(rra(map))));
	free((int *)cost_best);
}

static void	push_with_chunk_to_b(t_stack *map, t_stack *b, t_list **lst, int n)
{
	static int	chunk = -1;
	size_t		size;

	chunk += n;
	if (map->size == 0)
		return ;
	size = map->size;
	while (size > 0)
	{
		if (map->tab[0] >= (chunk - n) && map->tab[0] <= chunk)
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(pb(map, b))));
		else
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(ra(map))));
		size--;
	}
	push_with_chunk_to_b(map, b, lst, n);
}

/**
 * Cet algo tri la stack a (ici map) par ordre croissant en utilisant la stack
 * b. Une premiere phase en pushant les element de a dans b par un systeme 
 * default chunks. Puis il va push les elements de b vers a en un minimum de 
 * couts. Pour finir il va faire tourner les elements de a pour mettre le min 
 * en haut.
 */
t_list	*algo(t_stack *map, t_stack *b)
{
	t_list		*lst;
	int			n;

	if (map->size < 4)
		n = 4;
	else
		n = map->size / 4;
	lst = NULL;
	print_stack(map, b);
	push_with_chunk_to_b(map, b, &lst, n);
	ft_printf("\n Fin algo_part1");
	print_stack(map, b);
	while (b->size > 0)
	{
		push_best_to_a(map, b, &lst);
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(pa(map, b))));
		print_stack(map, b);
	}
	rotate_min_to_top(map, &lst);
	print_stack(map, b);
	return (lst);
}
