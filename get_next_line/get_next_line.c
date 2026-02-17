/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:24:20 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/17 09:02:21 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_store(int fd, char *memory)
{
	char		*buffer;
	long		bytes;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	bytes = 1;
	while (!ft_strchr(memory, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(memory), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = memory;
		memory = ft_strjoin(memory, buffer);
		free(temp);
		if (!memory)
			return (NULL);
	}
	free(buffer);
	return (memory);
}

static char	*extract_one_line(char *memory)
{
	char	*line;
	int		i;

	if (!memory || !*memory)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		line = ft_substr(memory, 0, i + 1);
	else
		line = ft_substr(memory, 0, i);
	return (line);
}

static char	*memory_update(char *memory)
{
	int		i;
	char	*new_memory;

	if (!memory)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	i++;
	new_memory = ft_strdup(memory + i);
	free(memory);
	return (new_memory);
}

char	*invalid_fd_memory(int fd, char *memory)
{
	if (fd < 0)
	{
		if (memory)
		{
			free(memory);
			memory = NULL;
		}
		return (NULL);
	}
	if (!memory)
	{
		memory = ft_strdup("");
		if (!memory)
			return (NULL);
	}
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	memory = invalid_fd_memory(fd, memory);
	memory = read_store(fd, memory);
	if (!memory)
		return (NULL);
	if (!*memory)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	line = extract_one_line(memory);
	if (!line)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	memory = memory_update(memory);
	return (line);
}
