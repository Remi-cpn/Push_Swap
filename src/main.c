/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/15 14:53:00 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Cette fonction free une stack et la mets a null.
 **/
static void	free_stack(t_stack *a, t_stack *b, t_stack *map)
{
	if (a)
	{
		free(a->tab);
		a->tab = NULL;
		free(a);
		a = NULL;
	}
	if (b)
	{
		free(b->tab);
		b->tab = NULL;
		free(b);
		b = NULL;
	}
	if (map)
	{
		free(map->tab);
		map->tab = NULL;
		free(map);
		map = NULL;
	}
}

/**
 * Cette fonction initialise une stack.
 */
static t_stack	*init_stack(int ac, size_t size)
{
	struct s_stack	*new;

	new = malloc(sizeof(struct s_stack));
	if (!new)
		return (NULL);
	new->tab = ft_calloc(ac, sizeof(int));
	if (!new->tab)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new->size = size;
	return (new);
}

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
	a = init_stack(ac, ac - 1);
	map = init_stack(ac, ac - 1);
	b = init_stack(ac, 0);
	if (!a || !b || !map)
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
