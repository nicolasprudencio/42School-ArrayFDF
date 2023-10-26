/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:19:55 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 12:52:00 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_libx	*init_window(void)
{
	t_libx	*window;

	window = malloc(sizeof(t_libx) * 1);
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, WIDTH, HEIGHT, "follen");
	window->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	window->addr = mlx_get_data_addr(window->img, &window->bits_per_pixel,
			&window->line_length, &window->endian);
	return (window);
}

int	check_key(int key, void *param)
{
	if (key == 65307)
		mlx_loop_end(param);
	return (0);
}

void	mlx_loop_management(t_data *data)
{
	mlx_key_hook(data->window->mlx_win, check_key, data->window->mlx);
	mlx_hook(data->window->mlx_win, 17, 1L << 17, mlx_loop_end,
		data->window->mlx),
	mlx_loop(data->window->mlx);
}

void	destroy_window(t_libx *window)
{
	if (!window)
		return ;
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	free(window);
}
