/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:33:15 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/06 18:15:31 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	find_map_size(t_data *data, char *file);

t_data	*parse_data(char *file)
{	
	t_data	*data;
	char	**split_file;
	int		area;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	area = find_map_size(data, file);
	split_file = ft_split(file, ' ');
	if (!split_file)
		return (NULL);
	else if (area != ft_gridlen(split_file))
	{	
		free_file(split_file, file);
		free(data);
		return (NULL);
	}
	find_sin_cos(data);
	define_vectors(data, split_file);
	free_file(split_file, file);
	return (data);
}

void	find_sin_cos(t_data *data)
{
	double		pi_div;

	pi_div = M_PI / 180;
	data->radian_cos = cos(45 * (pi_div));
	data->radian_sin = sin(30 * (pi_div));
}

static char	*fp_strnxt(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] && s[i] != (char) c)
		;
	if (s[i] && s[i + 1] && s[i] == (char)c)
		return ((char *)&s[i + 1]);
	return (NULL);
}

void	define_vectors(t_data *data, char **map_data)
{
	int			i;
	int			x;
	int			y;

	i = -1;
	data->matrix = (t_vector **)ft_calloc(data->max_y + 1, sizeof(t_vector *));
	while (++i < data->max_y)
		data->matrix[i] = (t_vector *)ft_calloc(data->max_x + 1,
				sizeof(t_vector));
	i = 0;
	y = -1;
	while (++y < data->max_y)
	{	
		x = -1;
		while (++x < data->max_x)
		{	
			data->matrix[y][x].y = y;
			data->matrix[y][x].x = x;
			data->matrix[y][x].z = ft_atoi(map_data[i]);
			data->matrix[y][x].color = ft_atox(fp_strnxt(map_data[i], ','));
			i++;
		}
	}
}

int	find_map_size(t_data *data, char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{	
		if (file[i] == '\n')
		{	
			file[i] = ' ';
			data->max_y++;
		}
		if (data->max_y == 0 && file[i] != ' ' && (file[i + 1] == ' '
				|| file[i + 1] == '\n'))
			data->max_x++;
	}
	return (data->max_x * data->max_y);
}
