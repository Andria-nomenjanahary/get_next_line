/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:24:25 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/17 09:05:41 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((void *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((void *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*res;

	if (!s)
		return (malloc(1));
	i = 0;
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newsub;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	if (len >= slen - start)
		len = slen - start;
	newsub = malloc((len + 1) * sizeof(char));
	if (!newsub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newsub[i] = s[start + i];
		i++;
	}
	newsub[i] = '\0';
	return (newsub);
}
