/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:04:51 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 19:20:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_tab_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

/**
 * Cette fonction free une stack et la mets a null.
 **/
void	free_stack(t_stack *a, t_stack *b, t_stack *map)
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
t_stack	*init_stack(int ac, size_t size)
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

/**
 * Cette fonction initialise une structure.
 */
t_bit	*init_bit(int bit_max, int index)
{
	struct s_bit	*new;

	new = malloc(sizeof(struct s_bit));
	if (!new)
		return (NULL);
	new->max = bit_max;
	new->index = index;
	return (new);
}
