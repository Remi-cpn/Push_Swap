/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:30:46 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/08 16:32:08 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*count_rr_or_rrr(t_list *curent, char *str1, char *str2, int size)
{
	t_list	*tmp;
	int		*count;

	count = ft_calloc(3, sizeof(int));
	if (!count)
		return (NULL);
	tmp = curent;
	while (tmp && ((char *)tmp->content)[0] == 'r')
	{
		if (ft_strncmp(tmp->content, str1, size) == 0)
			count[0]++;
		if (ft_strncmp(tmp->content, str2, size) == 0)
			count[1]++;
		tmp = tmp->next;
	}
	return (count);
}

void	put_space(t_list *curent, int i)
{
	while (i > 0)
	{
		((char *)curent->content)[0] = ' ';
		curent = curent->next;
		i --;
	}
}
