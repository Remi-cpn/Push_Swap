/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/12 15:59:01 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*init_stack(int ac)
{
	struct s_stack	*new;

	new = malloc(sizeof(struct s_stack));
	if (!new)
		return (NULL);
	new->tab = ft_calloc(ac + 1, sizeof(int));
	if (!new->tab)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	return (new);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	int		i;

	if (ac <= 1)
	{
		write(2, "Arg ?\n", 6);
		return (0);
	}
	a = init_stack(ac);
	i = 0;
	while (i < ac - 1)
	{
		a->tab[i] = ft_atoi(av[i + 1]);
		ft_printf("Tab[%d] = %d\n", i, a->tab[i]);
		i++;
	}
	sa(a);
	ft_printf("Apres sa:\nTab[0] = %d\nTab[1] = %d\n", a->tab[0], a->tab[1]);
	free(a->tab);
	free(a);
	return (0);
}
