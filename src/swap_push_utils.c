/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:29:31 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/12 15:44:05 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Swap the first 2 elements at the top of stack a.
 **/
void	sa(t_stack *a)
{
	int	tmp;

	tmp = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = tmp;
}
/**
 * Swap the first 2 elements at the top of stack b.
 **/
void	sb(t_stack *b)
{
	int	tmp;

	tmp = b->tab[0];
	b->tab[0] = b->tab[1];
	b->tab[1] = tmp;
}

/**
 * Swap the first 2 elements at the top of stack a and swap the first elements
 * at the top of stack b in the same time
 **/
void	ss(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->tab[0];
	a->tab[0] = a->tab[1];
	a->tab[1] = tmp;
	tmp = b->tab[0];
	b->tab[0] = b->tab[1];
	b->tab[1] = tmp;
}
