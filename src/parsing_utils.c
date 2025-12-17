/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:14:45 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/17 18:34:30 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	

/**
 * This function checks if the string contains no digits.
 */
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

/**
 * This function checks if the value is already present in my stack.
 */
int	already_exit(t_stack *a, int nbr)
{
	size_t	i;

	i = 0;
	while (i < a->size && a->size > 0)
	{
		if (a->tab[i] == nbr)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
