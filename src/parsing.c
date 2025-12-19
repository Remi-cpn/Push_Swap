/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:24:34 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/19 13:35:59 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"	
#include <limits.h>

/**
 * This function fills my stack while controlling INT_MIN and INT_MAX as well 
 * as the repetition of values.
 */
static int	build_a(t_stack *a, char **str, int flag)
{
	int	i;

	i = 0;
	while (str[i] && flag == 0)
	{
		if (ft_atol(str[i]) > INT_MAX || ft_atol(str[i]) < INT_MIN)
			flag = ERROR;
		if (flag == 0 && already_exit(a, ft_atoi(str[i])) == TRUE)
			flag = ERROR;
		if (flag == 0)
			a->tab[i] = ft_atoi(str[i]);
		a->size++;
		i++;
	}
	if (flag == ERROR)
	{
		free_stack(a, NULL, NULL);
		write(2, "Error\n", 6);
	}
	free_tab_str(str);
	return (flag);
}

/**
 * This function counts the number of values in a string.
 */
static int	parsing_count(char *str)
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

/**
 * This function puts the different arguments into a single string 
 * separated by spaces.
 */
static char	*parsing_join(int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < ac)
	{
		str = ft_strjoin(str, av[i + 1], 1, 0);
		if (!str)
			return (NULL);
		str = ft_strjoin(str, " ", 1, 0);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

/**
 * This function checks the validity of the arguments.
 */
static int	parsing_check(int ac, char **av, int flag)
{
	int		i;
	char	c;

	while (ac > 0 && flag == 0)
	{
		i = -1;
		if (empty_str(av[ac]) == TRUE)
			flag = ERROR;
		while (av[ac][++i] && flag == 0)
		{
			c = av[ac][i];
			if (ft_isdigit(c) && av[ac][i + 1] != '-' && av[ac][i + 1] != '+')
				continue ;
			if ((c == '+' || c == '-') && ft_isdigit(av[ac][i + 1]))
				continue ;
			if (c == ' ')
				continue ;
			flag = ERROR;
		}
		ac--;
	}
	if (flag == ERROR)
		write(2, "Error\n", 6);
	return (flag);
}

/**
 * This function is the master function of the parsing. 
 * It controls the return in case of a malloc failure.
 */
t_stack	*parsing(int ac, char **av)
{
	char		*str;
	char		**tab_str;
	t_stack		*a;
	int			count;

	if (parsing_check(ac - 1, av, 0) == ERROR)
		return (NULL);
	str = parsing_join(ac - 1, av);
	if (!str)
		return (NULL);
	count = parsing_count(str);
	tab_str = ft_split(str, ' ');
	free(str);
	str = NULL;
	if (!tab_str)
		return (NULL);
	a = init_stack(count, 0);
	if (!a)
	{
		free_tab_str(tab_str);
		return (NULL);
	}
	if (build_a(a, tab_str, 0) == ERROR)
		return (NULL);
	return (a);
}
