/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:24:34 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 17:56:56 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	
#include <stdlib.h>
#include <limits.h>

/**
 * Cette fonction initialise la Stack a.
 */
static int	init_a(t_stack *a, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
			return (-1);
		a->tab[i] = atoi(str[i]);
		i++;
	}
	free_tab_str(str);
	return (0);
}

/**
 * Cette fonction count le nombre d'int present dans str.
 */
static int	parcing_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-' || ft_isdigit(str[i]))
		{
			count++;
			i++;
		}
		while (ft_isdigit(str[i]))
			i++;
	}
	return (count);
}

static char	*parcing_join(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < ac)
	{
		tmp = ft_strjoin(str, av[i + 1]);
		free(str);
		str = NULL;
		str = ft_strjoin(tmp, " ");
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (str);
}

/**
 * Cette fonction renvoi 'Erreur' sur les arguments ne sont pas valides.
 */
static int	parcing_check(int ac, char **av)
{
	int		i;
	char	c;
	char	count;

	count = 0;
	while (ac > 0)
	{
		i = -1;
		while (av[ac][++i])
		{
			c = av[ac][i];
			count++;
			if (ft_isdigit(c) && av[ac][i + 1] != '-' && av[ac][i + 1] != '+')
				continue ;
			if ((c == '+' || c == '-') && ft_isdigit(av[ac][i + 1]))
				continue ;
			if (c == ' ')
				continue ;
			write(1, "Error", 5);
			return (-1);
		}
		ac--;
	}
	return (count);
}

t_stack	*parsing(int ac, char **av)
{
	const int	check = parcing_check(ac - 1, av);
	char		*str;
	char		**tab_str;
	t_stack		*a;
	int			count;

	if (check == -1)
		return (NULL);
	str = parcing_join(ac - 1, av);
	count = parcing_count(str);
	tab_str = ft_split(str, ' ');
	free(str);
	str = NULL;
	a = init_stack(count, count);
	if (!a)
	{
		free_tab_str(tab_str);
		return (NULL);
	}
	if (init_a(a, tab_str) == -1)
		return (NULL);
	return (a);
}
