/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:24:20 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/13 15:56:28 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_store(int fd, char *memory)
{
	char		buffer[BUFFER_SIZE + 1];
	size_t		bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(memory, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (NULL);
		buffer[bytes] = '\0';
		memory = ft_strjoin(memory, buffer);
	}
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
	if (!line)
		return (NULL);
	return (line);
}

static char	*memory_update(char *memory)
{
	int		i;
	char	*new_memory;

	i = 0;
	if (!memory)
		return (NULL);
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

char	*get_next_line(int fd)
{
	static char	*memory = "";
	char		*line;

	memory = read_store(fd, memory);
	if (!memory || !*memory)
		return (NULL);
	line = extract_one_line(memory);
	memory = memory_update(memory);
	return (line);
}
