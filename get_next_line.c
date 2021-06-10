/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:33:48 by vdragomi          #+#    #+#             */
/*   Updated: 2021/06/09 21:42:53 by vdragomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line_checker(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)s + i);
		else
			i++;
	}
	return (NULL);
}

int	ft_memory_check(int fd, char **line, char **buff)
{
	if ((read(fd, NULL, 0) < 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	*buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	return (1);
}

char	*ft_res_checker(char **res, char **line)
{
	char	*pnl;

	pnl = NULL;
	if (*res)
	{
		pnl = ft_new_line_checker(*res);
		if (pnl)
		{
			*pnl = '\0';
			*line = ft_strdup(*res);
			pnl++;
			ft_strcpy(*res, pnl);
		}
		else
		{
			*line = ft_strdup(*res);
			free(*res);
			*res = NULL;
		}
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	return (pnl);
}

int	get_next_line(int fd, char **line)
{
	static char	*res;
	char		*buff;
	char		*pnl;
	int			read_value;

	pnl = NULL;
	read_value = 1;
	if (ft_memory_check(fd, line, &buff) < 0)
		return (-1);
	pnl = ft_res_checker(&res, line);
	while (!pnl && read_value > 0)
	{
		read_value = read(fd, buff, BUFFER_SIZE);
		buff[read_value] = '\0';
		pnl = ft_new_line_checker(buff);
		if (pnl)
		{
			*pnl = '\0';
			pnl++;
			res = ft_strdup(pnl);
		}
		*line = ft_strjoin(*line, buff);
	}
	free(buff);
	return (read_value && res);
}
