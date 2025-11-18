/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:26:36 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/18 21:53:49 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*replace(char *sec, char *bad1, char *bad2)
{
	int	i;
	int	tmp;

	i = 0;
	while (sec[i])
	{
		if (sec[i] == bad1[0])
		{
			if (ft_memcmp(&sec[i], bad1, ft_strlen(bad1)) == 0)
			{
				tmp = i + (int)ft_strlen(bad1);
				while (sec[tmp] == ' ')
					tmp++;
				if (ft_memcmp(&sec[tmp], bad2, ft_strlen(bad2)) == 0)
				{
					tmp = tmp + (int)ft_strlen(bad2);
					while (i < tmp)
					{
						sec[i] = ' ';
						i++;
					}
					i = 0;
					continue ;
				}
			}
		}
		i++;
	}
	return (sec);
}

int	bit_max(size_t index_max)
{
	static int	nbr_bit = 0;

	if (index_max == 0)
		return (0);
	bit_max(index_max / 2);
	nbr_bit++;
	return (nbr_bit);
}

char	*strjoin_wish(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc(size_s1 + size_s2 + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, size_s1);
	ft_memcpy(dest + size_s1, s2, size_s2);
	dest[size_s1 + size_s2] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (dest);
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
