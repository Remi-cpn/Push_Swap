/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:06:16 by rcompain          #+#    #+#             */
/*   Updated: 2025/10/16 12:30:27 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*dup;

	size = ft_strlen((char *)s) + 1;
	dup = (char *)malloc(sizeof(char) * (size));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s, size);
	return (dup);
}
