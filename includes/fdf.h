/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:24:43 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/18 14:25:57 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif 

# include <libft.h>
# include <mlx.h>

typedef struct s_vector {
	int	y;
	int	x;
	int	z;
	int	color;
}				t_vector;

typedef struct s_libx
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_libx;

typedef struct s_data
{
	t_libx		*window;
	int			max_y;
	int			max_x;
	t_vector	**matrix;
	float		scale;
	int			offset_x;
	int			offset_y;
	double		radian_sin;
	double		radian_cos;
}				t_data;

t_libx		*init_window(void);
void		destroy_window(t_libx *window);
char		*read_file(char *file);
int			find_map_size(t_data *data, char *file);
t_data		*parse_data(char *file);
void		define_vectors(t_data *data, char **map_data);
void		free_file(char **splited_file, char *file);
void		draw_map(t_data *data);
void		free_matrix(t_vector **matrix);
void		mlx_loop_management(t_data *data);
int			check_key(int key, void *param);
void		find_scale(t_data *data);
void		find_max_size(t_data *data, char *file);
void		find_sin_cos(t_data *data);

#endif
