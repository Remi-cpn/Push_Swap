/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/20 13:52:51 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * This function sends the move instructions to output 1.
 */
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

/**
 * This function calls the algorithm function, the optimization function, and 
 * then the function to print the instructions.
 **/
static int	algo_waver(t_stack *map, t_stack *b)
{
	t_list	*lst;
	int		flag;

	flag = 0;
	lst = algo_sort(map, b, 0);
	if (!lst)
		return (ERROR);
	flag = opti(&lst);
	if (flag == 0)
		print_lst(lst);
	ft_lstclear(&lst, free);
	return (flag);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*map;
	int		flag;

	if (ac <= 1)
		return (1);
	a = parsing(ac, av);
	if (!a)
		return (1);
	map = init_stack(a->size, a->size);
	b = init_stack(a->size, 0);
	if (!b || !map)
	{
		free_stack(a, b, map);
		return (1);
	}
	mapping(a, map);
	flag = algo_waver(map, b);
	free_stack(a, b, map);
	if (flag == ERROR)
		return (1);
	return (0);
}
