/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:40:27 by glancell          #+#    #+#             */
/*   Updated: 2025/03/06 02:17:17 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	projectandtrackpoint(t_vars *vars, t_draw *d, float x, float y)
{
	t_3d_point		point;
	t_point			projected;
	static t_bounds	bounds = {1200, 900, 0, 0};

	point = create_3d_point((float)x, (float)y,
			(float)vars->map->matrix[(int)y][(int)x],
			vars->map->colors[(int)y][(int)x]);
	projected = project_point(point, vars, d);
	bounds.min_x = fmin(bounds.min_x, projected.x);
	bounds.min_y = fmin(bounds.min_y, projected.y);
	bounds.max_x = fmax(bounds.max_x, projected.x);
	bounds.max_y = fmax(bounds.max_y, projected.y);
	if ((int)y == vars->map->height - 1 && (int)x == vars->map->width - 1)
	{
		d->offset_x = 600.0f - (bounds.min_x + bounds.max_x) / 2.0f;
		d->offset_y = 450.0f - (bounds.min_y + bounds.max_y) / 2.0f;
	}
	return (projected);
}

static void	initialize_bounds(t_bounds *bounds)
{
	bounds->min_x = WINDOW_WIDTH;
	bounds->min_y = WINDOW_HEIGHT;
	bounds->max_x = 0;
	bounds->max_y = 0;
}

static void	calculate_offsets(t_draw *d, t_bounds *bounds)
{
	d->offset_x = (WINDOW_WIDTH - (bounds->max_x - bounds->min_x)) / 1.5f
		- bounds->min_x;
	d->offset_y = (WINDOW_HEIGHT - (bounds->max_y - bounds->min_y)) / 1.7f
		- bounds->min_y;
}

void	calculate_bounds(t_vars *vars, t_draw *d)
{
	t_bounds	bounds;
	int			i;
	int			j;

	initialize_bounds(&bounds);
	i = 0;
	while (i < vars->map->height)
	{
		j = 0;
		while (j < vars->map->width)
		{
			projectandtrackpoint(vars, d, (float)j, (float)i);
			j++;
		}
		i++;
	}
	calculate_offsets(d, &bounds);
}

t_3d_point	create_point_at_coords(t_map *map, int x, int y)
{
	return (create_3d_point(
			(float)x,
			(float)y,
			(float)map->matrix[y][x],
		map->colors[y][x]
	));
}
