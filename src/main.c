/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/08 17:06:20 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%s", tmp->content);
		tmp = tmp->next;
	}
}

static int	algo(t_stack *map, t_stack *b)
{
	t_list	*lst;

	lst = algo_sort(map, b, 0);
	if (!lst)
		return (-1);
	opti(&lst);
	print_lst(lst);
	ft_lstclear(&lst, free);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*map;

	if (ac <= 1)
	{
		write(2, "Arg ?\n", 6);
		return (0);
	}
	a = parsing(ac, av);
	if (!a)
		return (0);
	map = init_stack(a->size, a->size);
	b = init_stack(a->size, 0);
	if (!b || !map)
	{
		free_stack(a, b, map);
		return (0);
	}
	mapping(a, map);
	algo(map, b);
	free_stack(a, b, map);
}
