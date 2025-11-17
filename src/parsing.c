/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:24:34 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/17 15:31:47 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	
#include <stdlib.h>
#include <limits.h>

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
	free_str_str(str);
	return (0);
}

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
	char		**str2;
	t_stack		*a;
	int			count;

	if (check == -1)
		return (NULL);
	str = parcing_join(ac - 1, av);
	ft_printf("%s\n", str);
	count = parcing_count(str);
	ft_printf("%d\n", count);
	str2 = ft_split(str, ' ');
	free(str);
	str = NULL;
	a = init_stack(count, count);
	if (!a)
	{
		free_str_str(str2);
		return (NULL);
	}
	if (init_a(a, str2) == -1)
		return (NULL);
	return (a);
}
