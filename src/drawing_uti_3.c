/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_uti_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:15:06 by glancell          #+#    #+#             */
/*   Updated: 2025/03/04 19:58:43 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal_lines(t_vars *vars, t_draw *d, int y)
{
	t_point		current;
	t_point		next;
	t_3d_point	current_3d;
	t_3d_point	next_3d;
	int			x;

	x = 0;
	while (x < vars->map->width - 1)
	{
		current_3d = create_point_at_coords(vars->map, x, y);
		current = project_point(current_3d, vars, d);
		next_3d = create_point_at_coords(vars->map, x + 1, y);
		next = project_point(next_3d, vars, d);
		draw_line(vars, current, next);
		x++;
	}
}

static void	draw_vertical_lines(t_vars *vars, t_draw *d, int y)
{
	t_point		current;
	t_point		next;
	t_3d_point	current_3d;
	t_3d_point	next_3d;
	int			x;

	x = 0;
	while (x < vars->map->width)
	{
		current_3d = create_point_at_coords(vars->map, x, y);
		current = project_point(current_3d, vars, d);
		if (y < vars->map->height - 1)
		{
			next_3d = create_point_at_coords(vars->map, x, y + 1);
			next = project_point(next_3d, vars, d);
			draw_line(vars, current, next);
		}
		x++;
	}
}

void	draw_map(t_vars *vars)
{
	t_draw	d;
	int		y;

	clear_image(vars);
	d.cell_size = 40.0f;
	calculate_bounds(vars, &d);
	y = 0;
	while (y < vars->map->height)
	{
		draw_horizontal_lines(vars, &d, y);
		draw_vertical_lines(vars, &d, y);
		y++;
	}
}
