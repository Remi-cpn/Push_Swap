/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/12 18:10:11 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Cette fonction free une stack et la mets a null.
 **/
static void	free_stack(t_stack *a, t_stack *b)
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
	ft_printf("%d\n", new->size);
	return (new);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (ac <= 1)
	{
		write(2, "Arg ?\n", 6);
		return (0);
	}
	a = init_stack(ac, ac - 1);
	b = init_stack(ac, 0);
	if (!a || !b)
	{
		free_stack(a, b);
		return (0);
	}
	i = 0;
	while (i < ac - 1)
	{
		a->tab[i] = ft_atoi(av[i + 1]);
		ft_printf("a->tab[%d] = %d\n", i, a->tab[i]);
		ft_printf("b->tab[%d] = %d\n", i, b->tab[i]);
		i++;
	}
	pb(a, b);
	pa(a, b);
	i = 0;
	while (i < (int)a->size)
	{
		ft_printf("%d", a->tab[i]);
		i++;
	}
	ft_printf("\nTaille de a = %d\n", a->size);
	i = 0;
	while (i < (int)b->size)
	{
		ft_printf("%d", b->tab[i]);
		i++;
	}
	ft_printf("\nTaille de b = %d\n", b->size);
	free_stack(a, b);
	return (0);
}
