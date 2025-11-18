/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:16:38 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 20:55:01 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	exec(t_stack *a, t_stack *b, char *sec)
{
	int	i;

	i = 0;
	while (sec[i])
	{
		if (sec[i] == 'p')
		{
			if (sec[i + 1] == 'a')
				pa(a, b);
			else
				pb(a, b);
		}
		if (sec[i] == 'r')
			ra(a);
		i++;
	}
	print_stack(a, b, 0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*map;
	int		count;
	char	*sec;

	if (ac <= 1)
	{
		write(2, "Arg ?\n", 6);
		return (0);
	}
	a = parsing(ac, av);
	if (!a)
		return (0);
	map = init_stack(a->size, a->size);
	b = init_stack(a->size, 0);
	if (!b || !map)
	{
		free_stack(NULL, b, map);
		return (0);
	}
	/* TEST */
	mapping(a, map);
	sec = algo(map, b);
	count = ft_count_word(sec, ' ');
	exec(a, b, sec);
	ft_printf("\n\n Nombre de couts = %d\n", count);
	free_stack(a, b, map);
	free(sec);
	return (0);
}

/**
* Penser a controller ce qui ce passe si size 1 dans bit_max
*/
