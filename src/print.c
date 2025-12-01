/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:38:25 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/25 16:46:30 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int	i;

	ft_printf("\nStack A\t\tStack B \n");
	i = 0;
	while (i < (int)a->size || i < (int)b->size)
	{
		if (i < (int)a->size)
			ft_printf("%d\t\t", a->tab[i]);
		else
			ft_printf("\t\t");
		if (i < (int)b->size)
			ft_printf("%d\n", b->tab[i]);
		else
			ft_printf("\n");
		i++;
	}
}
