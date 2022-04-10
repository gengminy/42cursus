/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:56:00 by knoh              #+#    #+#             */
/*   Updated: 2022/03/14 14:56:01 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

static char	*read_line(int fd, char *backup)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	size = 1;
	while (!ft_strchr(backup, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[size] = 0;
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

static char	*parse_line(char *backup)
{
	char	*ret;
	size_t	i;

	if (!backup[0])
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	ret = (char *)malloc(i + 2);
	if (!ret)
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		ret[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		ret[i] = backup[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*change_backup_elem(char *backup)
{
	char	*ret;
	int		i;
	int		len;

	len = 0;
	while (backup[len] && backup[len] != '\n')
		len++;
	if (!backup[len])
	{
		free(backup);
		return (0);
	}
	ret = (char *)malloc(ft_strlen(backup) - len++ + 1);
	if (!ret)
		return (0);
	i = -1;
	while (backup[len + ++i])
		ret[i] = backup[len + i];
	ret[i] = 0;
	free(backup);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = read_line(fd, backup);
	if (!backup)
		return (0);
	next_line = parse_line(backup);
	backup = change_backup_elem(backup);
	return (next_line);
}
