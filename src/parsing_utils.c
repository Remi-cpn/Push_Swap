/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:14:45 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/08 19:52:49 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	
#include <stddef.h>

int	empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	already_exit(t_stack *a, int nbr)
{
	size_t	i;

	i = 0;
	if (a->tab[i] * 1 == 0 && nbr * 1 == 0)
		return (TRUE);
	while (i < a->size && (nbr * 1) != 0)
	{
		if ((a->tab[i] / nbr) == 1 && a->tab[i] % nbr == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
