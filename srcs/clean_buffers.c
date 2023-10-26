/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_buffers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:29:00 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:09:58 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	free_matrix(t_vector **matrix)
{	
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_file(char **splited_file, char *file)
{
	int	i;

	i = 0;
	while (splited_file[i])
		free(splited_file[i++]);
	free(splited_file);
	free(file);
}
