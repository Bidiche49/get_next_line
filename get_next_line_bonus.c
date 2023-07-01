/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntardy <ntardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:10:38 by ntardy            #+#    #+#             */
/*   Updated: 2022/06/12 11:21:23 by ntardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_is_bn(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_save_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i - 1] != '\n')
		i++;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
	return (buff);
}

static char	*ft_read_line(int fd, int res_read, char *buff, char *next_line)
{
	while (res_read > 0)
	{
		res_read = read(fd, buff, BUFFER_SIZE);
		buff[res_read] = '\0';
		if (ft_is_bn(buff))
		{
			next_line = ft_strcat_remake(next_line, buff);
			ft_save_buff(buff);
			return (next_line);
		}
		next_line = ft_strcat_remake(next_line, buff);
	}
	if (res_read < BUFFER_SIZE)
		buff[0] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	char		*next_line;
	int			res_read;

	res_read = 1;
	next_line = NULL;
	if (fd < 0 || fd > 1023)
		return (NULL);
	if (*buff[fd])
	{
		next_line = ft_strdup_remake(buff[fd], '\n');
		if (ft_is_bn(next_line))
		{
			ft_save_buff(buff[fd]);
			return (next_line);
		}
	}
	next_line = ft_read_line(fd, res_read, buff[fd], next_line);
	if (next_line[0] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}
