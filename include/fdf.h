/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <glancell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:01:23 by glancell          #+#    #+#             */
/*   Updated: 2025/09/25 20:46:31 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define ISO_ANGLE 0.523599f
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900

# define KEY_ESC 65307
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_T 116
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_M 109

typedef struct s_map
{
	int	**matrix;
	int	**colors;
	int	width;
	int	height;
}	t_map;

typedef struct s_camera
{
	float	alpha;
	float	beta;
	float	gamma;
	float	zoom;
	float	z_scale;
	float	x_offset;
	float	y_offset;
	int		projection;
}	t_camera;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
	t_camera	camera;
	int			show_menu;
}	t_vars;

typedef struct s_keymap
{
	int		key_code;
	int		(*func)(t_vars *);
}	t_keymap;

typedef struct s_point
{
	int		x;
	int		y;
	int		color;
}	t_point;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_line;

typedef struct s_draw
{
	float	cell_size;
	float	offset_x;
	float	offset_y;
}	t_draw;

typedef struct s_3d_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_3d_point;

typedef struct s_bounds
{
	float	min_x;
	float	min_y;
	float	max_x;
	float	max_y;
}	t_bounds;

void		free_map(t_map *map);
void		free_mlx(t_vars *vars);
int			parse_map(char *file, t_map *map);
void		gnl_clear_fd(int fd);
void		draw_map(t_vars *vars);
float		iso_x(float x, float y);
float		iso_y(float x, float y, float z);
void		put_pixel(t_vars *vars, int x, int y, int color);
void		clear_image(t_vars *vars);
int			ft_atoi_base(const char *str, int base);
int			count_elements(char **split);
void		free_split(char **split);
void		process_split_line(t_map *map, char **split, int y);
void		process_remaining_lines(t_map *map, int start_y);
int			get_map_height(char *file);
int			get_map_width(char *line);
int			parse_point(char *str, int *height, int *color);
int			zoom_in(t_vars *vars);
int			zoom_out(t_vars *vars);
int			rotate_x_plus(t_vars *vars);
int			rotate_x_minus(t_vars *vars);
int			rotate_y_plus(t_vars *vars);
int			rotate_y_minus(t_vars *vars);
int			translate_up(t_vars *vars);
int			translate_down(t_vars *vars);
int			translate_left(t_vars *vars);
int			translate_right(t_vars *vars);
int			toggle_projection(t_vars *vars);
int			toggle_menu(t_vars *vars);
void		render_menu(t_vars *vars);
void		draw_line(t_vars *vars, t_point start, t_point end);
void		apply_rotation(t_3d_point *point, t_camera *camera);
void		calculate_bounds(t_vars *vars, t_draw *d);
void		fill_map(t_map *map, int fd);
int			allocate_rows(t_map *map);
int			allocate_matrix(t_map *map);
void		render_view_setting(t_vars *vars, int *y_pos);
void		render_settings(t_vars *vars, int y_pos);
void		render_menu(t_vars *vars);
void		render_set_line(t_vars *vars, char *label, float value, int *y_pos);
char		*get_projection_name(int projection);
void		render_controls(void *mlx, void *win);
void		create_label_string(char *buffer, char *label);
int			close_window(t_vars *vars);
int			key_press(int keycode, void *param);
void		free_mlx_resources(t_vars *vars);
int			ft_abs(int n);
float		ft_cosf(float x);
float		ft_sinf(float x);
t_3d_point	create_point_at_coords(t_map *map, int x, int y);
t_3d_point	create_3d_point(float x, float y, float z, int color);
t_point		project_point(t_3d_point point, t_vars *vars, t_draw *d);

#endif