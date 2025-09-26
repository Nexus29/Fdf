/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_uti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:48:35 by glancell          #+#    #+#             */
/*   Updated: 2025/03/05 02:49:59 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_view_setting(t_vars *vars, int *y_pos)
{
	int		color;
	char	buffer[40];

	color = 0xFFFFFF;
	create_label_string(buffer, "View");
	mlx_string_put(vars->mlx, vars->win, 10, *y_pos, color, buffer);
	mlx_string_put(vars->mlx, vars->win,
		10 + 6 * 6, *y_pos, color,
		get_projection_name(vars->camera.projection));
}

void	render_settings(t_vars *vars, int y_pos)
{
	int	color;

	color = 0xFFFFFF;
	y_pos += 30;
	mlx_string_put(vars->mlx, vars->win, 10, y_pos, color, "Current Settings:");
	y_pos += 25;
	render_set_line(vars, "Zoom", vars->camera.zoom, &y_pos);
	render_set_line(vars, "Height Scale", vars->camera.z_scale, &y_pos);
	render_view_setting(vars, &y_pos);
}

void	render_menu(t_vars *vars)
{
	render_controls(vars->mlx, vars->win);
	render_settings(vars, 20 + 25 + 20 * 7);
}
