/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:10:05 by glancell          #+#    #+#             */
/*   Updated: 2025/03/04 19:58:43 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotate_x_plus(t_vars *vars)
{
	vars->camera.alpha += 0.05f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	rotate_x_minus(t_vars *vars)
{
	vars->camera.alpha -= 0.05f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	rotate_y_plus(t_vars *vars)
{
	vars->camera.beta += 0.05f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	rotate_y_minus(t_vars *vars)
{
	vars->camera.beta -= 0.05f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	toggle_projection(t_vars *vars)
{
	vars->camera.projection = !vars->camera.projection;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}
