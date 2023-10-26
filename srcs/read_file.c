/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:39:10 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/15 04:19:15 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char	*read_file(char *file)
{
	char	*lines;
	char	*aux;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = ft_strdup("");
	aux = get_next_line(fd);
	while (aux)
	{	
		lines = ft_strjoin(lines, aux, 2);
		aux = get_next_line(fd);
	}
	close(fd);
	return (lines);
}
