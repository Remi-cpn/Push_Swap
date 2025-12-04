/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:58:43 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/02 14:30:47 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Shift down all elements of stack a by 1. The last element becomes the 
 * first one.
 */
char	*rra(t_stack *a)
{
	int		tmp;
	size_t	i;

	if (a->size != 0)
	{
		i = a->size - 1;
		tmp = a->tab[i];
		while (i > 0)
		{
			a->tab[i] = a->tab[i - 1];
			i--;
		}
		a->tab[0] = tmp;
		return ("rra ");
	}
	return (NULL);
}

/**
 * Shift down all elements of stack b by 1. The last element becomes the 
 * first one.
 */
char	*rrb(t_stack *b)
{
	int		tmp;
	size_t	i;

	if (b->size != 0)
	{
		i = b->size - 1;
		tmp = b->tab[i];
		while (i > 0)
		{
			b->tab[i] = b->tab[i - 1];
			i--;
		}
		b->tab[0] = tmp;
		return ("rrb ");
	}
	return (NULL);
}

/**
 * rra and rrb at the same time.
 */
void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
