/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:30:37 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/12 16:32:07 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Removes lists with a space as the first character.
 */
static void	purify_space(t_list **lst, t_list *curent)
{
	t_list	*prev;

	prev = NULL;
	while (curent && curent->next)
	{
		if (((char *)curent->content)[0] == ' ')
		{
			if (!prev)
				*lst = curent->next;
			else
				prev->next = curent->next;
			ft_lstdelone(curent, free);
			curent = *lst;
			prev = NULL;
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}

/**
 * Replace rrb with rrr according to the number of consecutive rrb rra  
 * sequences.
 */
static void	replace_rrr(t_list *curent)
{
	int		*count;
	int		i;

	while (curent && curent->next)
	{
		if (ft_strncmp(curent->content, "rrb", 3) == 0)
		{
			count = count_rr_or_rrr(curent, "rrb", "rra", 3);
			i = 0;
			while (ft_strncmp(curent->content, "rrb", 3) == 0)
			{
				if (count[0] > i && count[1] > i)
				{
					((char *)curent->content)[2] = 'r';
					i++;
				}
				curent = curent->next;
			}
			put_space(curent, i);
			free(count);
		}
		else
			curent = curent->next;
	}
}

/**
 * Replace rb with rr according to the number of consecutive rb ra sequences.
 */
static void	replace_rr(t_list *curent)
{
	int		*count;
	int		i;

	while (curent && curent->next)
	{
		if (ft_strncmp(curent->content, "rb", 2) == 0)
		{
			count = count_rr_or_rrr(curent, "rb", "ra", 2);
			i = 0;
			while (ft_strncmp(curent->content, "rb", 2) == 0)
			{
				if (count[0] > i && count[1] > i)
				{
					((char *)curent->content)[1] = 'r';
					i++;
				}
				curent = curent->next;
			}
			put_space(curent, i);
			free(count);
		}
		else
			curent = curent->next;
	}
}

/**
 * Removes lists reproducing the sequence pb pa.
 */
static void	del_pa_pb(t_list **lst, t_list *curent)
{
	t_list	*prev;

	prev = NULL;
	while (curent && curent->next)
	{
		if (ft_strncmp(curent->content, "pb", 2) == 0
			&& ft_strncmp(curent->next->content, "pa", 2) == 0)
		{
			if (!prev)
				*lst = curent->next->next;
			else
				prev->next = curent->next->next;
			ft_lstdelone(curent->next, free);
			ft_lstdelone(curent, free);
			curent = *lst;
			prev = NULL;
		}
		else
		{
			prev = curent;
			curent = curent->next;
		}
	}
}

/**
 * This Fonction call diferrents optimisations fonctions.
 */
void	opti(t_list **lst)
{
	if (lst)
	{
		del_pa_pb(lst, *lst);
		replace_rr(*lst);
		replace_rrr(*lst);
		purify_space(lst, *lst);
	}
}
