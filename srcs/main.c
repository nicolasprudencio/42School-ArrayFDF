/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:40:33 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 12:49:48 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	throw_error(int type_error, char *file);

int	main(int argc, char **argv)
{	
	char	*file;
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments passed to call!\n", 2);
		return (1);
	}
	file = read_file(argv[1]);
	if (!file)
		return (throw_error(1, file));
	data = parse_data(file);
	if (!data)
		return (throw_error(2, file));
	data->window = init_window();
	draw_map(data);
	mlx_loop_management(data);
	destroy_window(data->window);
	free_matrix(data->matrix);
	free(data);
	return (0);
}

static int	throw_error(int type_error, char *file)
{
	if (type_error == 1)
	{	
		ft_putstr_fd("Error: file descriptor invalid!\n", 2);
		free(file);
		return (1);
	}
	else if (type_error == 2)
	{
		ft_putstr_fd("Error: Failed to allocate the map!", 2);
		return (1);
	}
	return (0);
}
