/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:29:31 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/15 17:31:48 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 **/
char	*sa(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)b;
	if (a->size > 1)
	{
		tmp = a->tab[0];
		a->tab[0] = a->tab[1];
		a->tab[1] = tmp;
	}
	return ("sa\n");
}

/**
 * Push the first elements at the top of stack b on the top of stack a.
 */
char	*pa(t_stack *a, t_stack *b)
{
	size_t	i;
	int		tmp;

	if (b->size > 0)
	{
		i = 1;
		a->size++;
		while (i < a->size)
		{
			tmp = a->tab[i];
			a->tab[i] = a->tab[0];
			a->tab[0] = tmp;
			i++;
		}
		a->tab[0] = b->tab[0];
		b->size--;
		i = 0;
		while (i < b->size)
		{
			b->tab[i] = b->tab[i + 1];
			i++;
		}
	}
	return ("pa\n");
}

/**
 * Push the first elements at the top of stack a on the top of stack b.
 */
char	*pb(t_stack *a, t_stack *b)
{
	size_t	i;
	int		tmp;

	if (a->size > 0)
	{
		i = 1;
		b->size++;
		while (i < b->size)
		{
			tmp = b->tab[i];
			b->tab[i] = b->tab[0];
			b->tab[0] = tmp;
			i++;
		}
		b->tab[0] = a->tab[0];
		a->size--;
		i = 0;
		while (i < a->size)
		{
			a->tab[i] = a->tab[i + 1];
			i++;
		}
	}
	return ("pb\n");
}
