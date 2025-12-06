/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/06 15:37:11 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exec(t_stack *a, t_stack *b, t_list *lst)
{
	t_list	*tmp;
	char	*cmd;

	tmp = lst;
	while (tmp)
	{
		cmd = (char *)tmp->content;
		if (ft_strncmp(cmd, "pa", 2) == 0)
			pa(a, b);
		else if (ft_strncmp(cmd, "pb", 2) == 0)
			pb(a, b);
		else if (ft_strncmp(cmd, "ra", 2) == 0)
			ra(a, b);
		else if (ft_strncmp(cmd, "rb", 2) == 0)
			rb(b, a);
		else if (ft_strncmp(cmd, "rra", 3) == 0)
			rra(a, b);
		else if (ft_strncmp(cmd, "rrb", 3) == 0)
			rrb(b, a);
		else if (ft_strncmp(cmd, "rrr", 3) == 0)
			rrr(a, b);
		else if (ft_strncmp(cmd, "rr", 2) == 0)
			rr(a, b);
		tmp = tmp->next;
	}
	print_stack(a, b);
}

static void	tri_ok(t_stack *a)
{
	int	i;

	i = 0;
	while (i < (int)a->size - 1)
	{
		if (a->tab[i] > a->tab[i + 1])
		{
			ft_printf("Tri KO a l'index %d\n", i);
			return ;
		}
		i++;
	}
	ft_printf("Tri OK");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*map;
	int		count;
	t_list	*lst;

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
		free_stack(NULL, b, map);
		return (0);
	}
	/* TEST */
	mapping(a, map);
	lst = algo_sort(map, b, 0);
	if (!lst)
		return (0);

	t_list	*tmp = lst;

	ft_printf("\nList =\n");
	while (tmp)
	{
		ft_printf("%s", tmp->content);
		tmp = tmp->next;
	}
	opti(&lst);
	tmp = lst;
	ft_printf("\nList Opti=\n");
	count = 0;
	while (tmp)
	{
		ft_printf("%s", tmp->content);
		tmp = tmp->next;
		count++;
	}
	exec(a, b, lst);
	ft_printf("\n\n Nombre de couts = %d\n", count);
	tri_ok(a);
	free_stack(a, b, map);
	ft_lstclear(&lst, free);
	return (0);
}
