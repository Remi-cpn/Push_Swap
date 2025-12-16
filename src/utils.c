/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:26:36 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/16 17:10:28 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	new_cmd(t_list **lst, t_stack *stack1, t_stack *stack2,
				char *(*cmd)(t_stack *, t_stack *))
{
	char		*dup;
	const char	*str;
	t_list		*new;

	if (!stack2)
		str = (const char *)cmd(stack1, NULL);
	else
		str = (const char *)cmd(stack1, stack2);
	dup = ft_strdup(str);
	if (!dup)
		return (ERROR);
	new = ft_lstnew(dup);
	if (!new)
		return (ERROR);
	ft_lstadd_back(lst, new);
	return (0);
}

int	stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->size > 1 && i < (int)stack->size - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	mapping(t_stack *a, t_stack *map)
{
	int	i;
	int	j;

	if (a->size == 0)
		return ;
	i = 0;
	map->tab[0] = 0;
	while (i < (int)a->size - 1)
	{
		i++;
		map->tab[i] = 0;
		j = 0;
		while (j < i)
		{
			if (a->tab[i] > a->tab[j])
				map->tab[i]++;
			else
				map->tab[j]++;
			j++;
		}
	}
}
