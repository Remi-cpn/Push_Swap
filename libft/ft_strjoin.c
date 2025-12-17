/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:11 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/17 18:55:44 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_str(const char *str)
{
	free((void *)str);
	str = NULL;
}

char	*ft_strjoin(char const *s1, char const *s2, int flag1, int flag2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc(size_s1 + size_s2 + 1);
	if (dest)
	{
		ft_memcpy(dest, s1, size_s1);
		ft_memcpy(dest + size_s1, s2, size_s2);
		dest[size_s1 + size_s2] = '\0';
	}
	if (flag1 == 1)
		free_str(s1);
	if (flag2 == 1)
		free_str(s2);
	return (dest);
}
