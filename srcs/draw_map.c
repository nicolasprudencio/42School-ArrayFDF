/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 02:41:51 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:10:44 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	put_pixel(t_libx *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + y * data->line_length + x
		* (data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

static void	to_isometric(t_vector *beg, t_vector *end, t_data *data)
{
	int			old_x;

	old_x = beg->x;
	beg->x = (beg->x - beg->y) * data->radian_cos;
	beg->y = (-beg->z + old_x + beg->y) * data->radian_sin;
	old_x = end->x;
	end->x = (end->x - end->y) * data->radian_cos;
	end->y = (-end->z + old_x + end->y) * data->radian_sin;
}

static void	draw_line(t_data *data, t_vector beg, t_vector end)
{
	double	t;
	int		x;
	int		y;
	double	precision;

	t = 0;
	precision = 0.001;
	beg.y = (beg.y - data->offset_y) * data->scale;
	beg.x = (beg.x - data->offset_x) * data->scale;
	beg.z = beg.z * (data->scale / 10);
	end.y = (end.y - data->offset_y) * data->scale;
	end.x = (end.x - data->offset_x) * data->scale;
	end.z = end.z * (data->scale / 10);
	to_isometric(&beg, &end, data);
	while (t <= 1)
	{
		x = ((1 - t) * beg.x + (t * end.x)) + (WIDTH / 2);
		y = (((1 - t) * beg.y + (t * end.y))) + (HEIGHT / 2);
		put_pixel(data->window, x, y, beg.color);
		t += precision;
	}
}

void	draw_map(t_data *data)
{
	int			y;
	int			x;
	t_vector	**map;

	y = -1;
	map = data->matrix;
	find_scale(data);
	y = -1;
	while (++y < data->max_y)
	{
		x = -1;
		while (++x < data->max_x)
		{
			if (x < data->max_x - 1)
				draw_line(data, map[y][x], map[y][x + 1]);
			if (y < data->max_y - 1)
				draw_line(data, map[y][x], map[y + 1][x]);
		}
	}
	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win,
		data->window->img, 0, 0);
}

void	find_scale(t_data *data)
{
	float		scale;

	if (WIDTH / (data->max_y) < HEIGHT / (data->max_x))
		scale = WIDTH / (data->max_y);
	else
		scale = HEIGHT / (data->max_x);
	data->offset_x = data->max_x / 2;
	data->offset_y = data->max_y / 2;
	data->scale = scale;
}
