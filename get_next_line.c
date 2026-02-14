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

static char *read_store(int fd, char *memory) {
  char buffer[BUFFER_SIZE + 1];
  ssize_t bytes;
  char *temp;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  bytes = 1;
  while (!ft_strchr(memory, '\n') && bytes > 0) {
    bytes = read(fd, buffer, BUFFER_SIZE);
    if (bytes < 0) {
      free(memory);
      return (NULL);
    }
    if (bytes == 0)
      break;
    buffer[bytes] = '\0';
    temp = memory;
    memory = ft_strjoin(memory, buffer);
    free(temp);
    if (!memory)
      return (NULL);
  }
  return (memory);
}

static char *extract_one_line(char *memory) {
  char *line;
  int i;

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

static char *memory_update(char *memory) {
  int i;
  char *new_memory;

  if (!memory)
    return (NULL);
  i = 0;
  while (memory[i] && memory[i] != '\n')
    i++;
  if (!memory[i]) {
    free(memory);
    return (NULL);
  }
  i++;
  new_memory = ft_strdup(memory + i);
  free(memory);
  return (new_memory);
}

char *get_next_line(int fd) {
  static char *memory;
  char *line;

  if (!memory) {
    memory = ft_strdup("");
    if (!memory)
      return (NULL);
  }

  memory = read_store(fd, memory);
  if (!memory)
    return (NULL);
  if (!*memory) {
    free(memory);
    memory = NULL;
    return (NULL);
  }
  line = extract_one_line(memory);
  memory = memory_update(memory);
  return (line);
}
