/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 22:27:52 by rcompain          #+#    #+#             */
/*   Updated: 2025/10/22 11:30:38 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_all(char **s, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**new;
	size_t	n_len;

	if (!s)
		return (NULL);
	n_len = count_word(s, c);
	new = ft_calloc((n_len + 1), sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < n_len)
	{
		while (*s == c)
			s++;
		new[i] = ft_substr(s, 0, wordlen(s, c));
		if (!new[i])
		{
			free_all(new, n_len);
			return (NULL);
		}
		s += wordlen(s, c);
		i++;
	}
	return (new);
}
