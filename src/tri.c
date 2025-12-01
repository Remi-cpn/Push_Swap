/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:04:54 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/28 19:09:28 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	algo_part3(t_stack *map, t_list **lst)
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

static void	algo_part2(t_stack *map, t_stack *b, t_list **lst)
{
	int			move;
	const int	*cost_best = check_best_index(map, b);
	const int	value = b->tab[cost_best[0]];

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

static void	algo_part1(t_stack *map, t_stack *b, t_list **lst, int n)
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
	algo_part1(map, b, lst, n);
}

t_list	*algo(t_stack *map, t_stack *b)
{
	t_list		*lst;
	const int	n = 170;

	lst = NULL;
	print_stack(map, b);
	algo_part1(map, b, &lst, n);
	ft_printf("\n Fin algo_part1");
	print_stack(map, b);
	while (b->size > 0)
	{
		algo_part2(map, b, &lst);
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(pa(map, b))));
		print_stack(map, b);
	}
	algo_part3(map, &lst);
	print_stack(map, b);
	return (lst);
}
