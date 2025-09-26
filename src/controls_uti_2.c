/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_uti_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:42:43 by glancell          #+#    #+#             */
/*   Updated: 2025/03/04 19:58:43 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom_in(t_vars *vars)
{
	vars->camera.zoom *= 1.1f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	zoom_out(t_vars *vars)
{
	vars->camera.zoom *= 0.9f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	toggle_menu(t_vars *vars)
{
	vars->show_menu = !vars->show_menu;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}
