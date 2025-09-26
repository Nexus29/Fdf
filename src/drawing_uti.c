/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_uti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:53:09 by glancell          #+#    #+#             */
/*   Updated: 2025/03/06 02:15:56 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	iso_x(float x, float y)
{
	return ((x - y) * ft_cosf(ISO_ANGLE));
}

float	iso_y(float x, float y, float z)
{
	return ((x + y) * ft_sinf(ISO_ANGLE) - z);
}

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	int	pixel_pos;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel_pos = (y * vars->line_length) + (x * (vars->bits_per_pixel / 8));
		*(unsigned int *)(vars->img_addr + pixel_pos) = color;
	}
}

void	clear_image(t_vars *vars)
{
	int	i;
	int	size;

	size = WINDOW_WIDTH * WINDOW_HEIGHT * (vars->bits_per_pixel / 8);
	i = 0;
	while (i < size)
	{
		vars->img_addr[i] = 0;
		i++;
	}
}

t_3d_point	create_3d_point(float x, float y, float z, int color)
{
	t_3d_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}
