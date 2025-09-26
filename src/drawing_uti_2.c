/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_uti_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:01:40 by glancell          #+#    #+#             */
/*   Updated: 2025/03/06 02:12:46 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_line_direction(t_line *line, t_point start, t_point end)
{
	line->dx = ft_abs(end.x - start.x);
	line->dy = ft_abs(end.y - start.y);
	line->sx = 1;
	if (start.x >= end.x)
		line->sx = -1;
	line->sy = 1;
	if (start.y >= end.y)
		line->sy = -1;
	line->err = line->dx - line->dy;
}

static void	update_line_position(t_point *start, t_line *line)
{
	line->e2 = line->err * 2;
	if (line->e2 > -line->dy)
	{
		line->err -= line->dy;
		start->x += line->sx;
	}
	if (line->e2 < line->dx)
	{
		line->err += line->dx;
		start->y += line->sy;
	}
}

void	draw_line(t_vars *vars, t_point start, t_point end)
{
	t_line	line;

	set_line_direction(&line, start, end);
	while (1)
	{
		put_pixel(vars, start.x, start.y, start.color);
		if (start.x == end.x && start.y == end.y)
			break ;
		update_line_position(&start, &line);
	}
}

void	apply_rotation(t_3d_point *point, t_camera *camera)
{
	float	x;
	float	y;
	float	z;

	y = point->y;
	z = point->z;
	point->y = y * ft_cosf(camera->alpha) - z * ft_sinf(camera->alpha);
	point->z = y * ft_sinf(camera->alpha) + z * ft_cosf(camera->alpha);
	x = point->x;
	z = point->z;
	point->x = x * ft_cosf(camera->beta) + z * ft_sinf(camera->beta);
	point->z = -x * ft_sinf(camera->beta) + z * ft_cosf(camera->beta);
	x = point->x;
	y = point->y;
	point->x = x * ft_cosf(camera->gamma) - y * ft_sinf(camera->gamma);
	point->y = x * ft_sinf(camera->gamma) + y * ft_cosf(camera->gamma);
}

t_point	project_point(t_3d_point point, t_vars *vars, t_draw *d)
{
	t_point	p;
	float	projected_x;
	float	projected_y;

	point.x *= vars->camera.zoom;
	point.y *= vars->camera.zoom;
	point.z *= vars->camera.zoom;
	point.z *= vars->camera.z_scale;
	apply_rotation(&point, &vars->camera);
	if (vars->camera.projection == 0)
	{
		projected_x = iso_x(point.x, point.y) * d->cell_size;
		projected_y = iso_y(point.x, point.y, point.z) * d->cell_size;
	}
	else
	{
		projected_x = point.x * d->cell_size;
		projected_y = point.y * d->cell_size;
	}
	p.x = (int)(projected_x + d->offset_x + vars->camera.x_offset);
	p.y = (int)(projected_y + d->offset_y + vars->camera.y_offset);
	p.color = point.color;
	return (p);
}
