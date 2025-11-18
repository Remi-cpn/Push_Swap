/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:29:31 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 20:21:23 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 **/
void	sa(t_stack *a)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->tab[0];
		a->tab[0] = a->tab[1];
		a->tab[1] = tmp;
	}
}

/**
 * Swap the first 2 elements at the top of stack b.
 **/
void	sb(t_stack *b)
{
	int	tmp;

	if (b->size > 1)
	{
		tmp = b->tab[0];
		b->tab[0] = b->tab[1];
		b->tab[1] = tmp;
	}
}

/**
 * Swap the first 2 elements at the top of stack a and swap the first elements
 * at the top of stack b in the same time
 **/
void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size > 1)
	{
		tmp = a->tab[0];
		a->tab[0] = a->tab[1];
		a->tab[1] = tmp;
	}
	if (b->size > 1)
	{
		tmp = b->tab[0];
		b->tab[0] = b->tab[1];
		b->tab[1] = tmp;
	}
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
	return ("pa ");
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
	return ("pb ");
}
