/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_uti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:38:35 by glancell          #+#    #+#             */
/*   Updated: 2025/03/04 19:58:43 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	translate_up(t_vars *vars)
{
	vars->camera.y_offset -= 10.0f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	translate_down(t_vars *vars)
{
	vars->camera.y_offset += 10.0f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	translate_left(t_vars *vars)
{
	vars->camera.x_offset -= 10.0f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}

int	translate_right(t_vars *vars)
{
	vars->camera.x_offset += 10.0f;
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	if (vars->show_menu)
		render_menu(vars);
	return (0);
}
