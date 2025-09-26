/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:36:56 by glancell          #+#    #+#             */
/*   Updated: 2025/03/06 01:00:26 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx_resources(t_vars	*vars)
{
	if (vars->img)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->img = NULL;
	}
	if (vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
}

int	close_window(t_vars *vars)
{
	if (!vars)
		return (0);
	if (vars->map)
	{
		free_map(vars->map);
		vars->map = NULL;
	}
	free_mlx_resources(vars);
	exit(0);
	return (0);
}
