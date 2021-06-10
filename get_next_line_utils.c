/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:59:55 by vdragomi          #+#    #+#             */
/*   Updated: 2021/06/08 17:21:33 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (i < l)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	y = 0;
	while (s1[y])
		str[i++] = s1[y++];
	y = 0;
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	free ((void *)s1);
	return (str);
}
