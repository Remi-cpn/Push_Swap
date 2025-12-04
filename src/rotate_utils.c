/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:27:02 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/02 14:33:51 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Shift up all elements of stack a by 1. The first element becomes the 
 * last one.
 */
char	*ra(t_stack *a)
{
	int		tmp;
	size_t	i;

	tmp = a->tab[0];
	i = 0;
	while (a->size != 0 && i < a->size - 1)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[i] = tmp;
	return ("ra ");
}

/**
 * Shift up all elements of stack b by 1. The first element becomes the 
 * last one.
 */
char	*rb(t_stack *b)
{
	int		tmp;
	size_t	i;

	tmp = b->tab[0];
	i = 0;
	while (b->size != 0 && i < b->size - 1)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[i] = tmp;
	return ("rb ");
}

/**
 * ra and rb at the same time.
 */
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
