/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:38:25 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/15 16:09:37 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *a, t_stack *b, int bit)
{
	int	i;

	if (bit != -1)
		ft_printf("\n\n-> Pour position bit %d\n", bit);
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
