/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvoandri <yvoandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:58:54 by yvoandri          #+#    #+#             */
/*   Updated: 2026/02/12 17:18:19 by yvoandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	const char	*fichier;
	size_t	read_bytes;
	char buffer[100];

	fichier = "fichier.txt";
	read_bytes = 50;
	int file = open(fichier, O_RDONLY);
	if (file == -1)
		printf("Open file error");
	read_bytes = read(file, buffer, read_bytes);
	printf("%s",buffer);

	printf("%s", ft_strjoin("bonjour ","vous"));
	
	return (0);
}
