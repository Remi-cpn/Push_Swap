/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:30:37 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/28 18:38:54 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	purify_space(t_list **lst, t_list *curent)
{
	t_list	*prev;

	if (!lst || !*lst)
		return ;
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

static int	*count_rr_or_rrr(t_list *curent, char *str1, char *str2, int size)
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

static void replace_rrr(t_list **lst, t_list *curent)
{
	int		*count;
	int		i;

	if(!lst || !*lst)
		return ;
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
			while (i > 0)
			{
				((char *)curent->content)[0] = ' ';
				i--;
				curent = curent->next;
			}
			free(count);
		}
		else
			curent = curent->next;
	}
}

static void replace_rr(t_list **lst, t_list *curent)
{
	int		*count;
	int		i;

	if(!lst || !*lst)
		return ;
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
			while (i > 0)
			{
				((char *)curent->content)[0] = ' ';
				i--;
				curent = curent->next;
			}
			free(count);
		}
		else
			curent = curent->next;
	}
}

static void	del_pa_pb(t_list **lst, t_list *curent)
{
	t_list	*prev;

	if (!lst || !*lst)
		return ;
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

void	opti(t_list **lst)
{
	del_pa_pb(lst, *lst);
	replace_rr(lst, *lst);
	replace_rrr(lst, *lst);
	purify_space(lst, *lst);
	t_list	*tmp = *lst;

	ft_printf("\nList dans opti\n");
	while (tmp)
	{
		ft_printf("%s", tmp->content);
		tmp = tmp->next;
	}

}
