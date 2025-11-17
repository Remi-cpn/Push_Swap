/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/17 15:17:50 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*map;
	int		i;
	int		count;

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
	i = 0;
	while (i < ac - 1)
	{
		a->tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	/* TEST */
	mapping(a, map);
	count = algo(map, b);

	ft_printf("\n\n Nombre de couts = %d\n", count);
	free_stack(a, b, map);
	return (0);
}

/**
* Penser a controller ce qui ce passe si size 1 dans bit_max
*/
