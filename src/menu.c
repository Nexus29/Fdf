/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:30:12 by glancell          #+#    #+#             */
/*   Updated: 2025/03/05 02:53:54 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_controls(void *mlx, void *win)
{
	int		y_pos;
	int		color;

	color = 0xFFFFFF;
	y_pos = 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "FdF Controls:");
	y_pos += 25;
	mlx_string_put(mlx, win, 10, y_pos, color, "Zoom: + / -");
	y_pos += 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "Rotate X: W / S");
	y_pos += 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "Rotate Y: A / D");
	y_pos += 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "Move: Arrow Keys");
	y_pos += 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "Toggle View: T");
	y_pos += 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "Toggle Menu: M");
	y_pos += 20;
	mlx_string_put(mlx, win, 10, y_pos, color, "Exit: ESC");
}

char	*get_projection_name(int projection)
{
	if (projection == 0)
		return ("Isometric");
	return ("Top-Down");
}

void	create_label_string(char *buffer, char *label)
{
	int	i;

	i = 0;
	while (label[i])
	{
		buffer[i] = label[i];
		i++;
	}
	buffer[i++] = ':';
	buffer[i++] = ' ';
	buffer[i] = '\0';
}

static void	format_float_to_string(char *buffer, float value)
{
	int	int_part;
	int	index;

	int_part = (int)value;
	index = 0;
	while (buffer[index] != ':')
		index++;
	index += 2;
	if (int_part < 10)
	{
		buffer[index] = int_part + '0';
		buffer[index + 1] = '\0';
	}
	else
	{
		buffer[index] = (int_part / 10) + '0';
		buffer[index + 1] = (int_part % 10) + '0';
		buffer[index + 2] = '\0';
	}
}

void	render_set_line(t_vars *vars, char *label, float value, int *y_pos)
{
	int		color;
	char	buffer[40];

	color = 0xFFFFFF;
	create_label_string(buffer, label);
	format_float_to_string(buffer, value);
	mlx_string_put(vars->mlx, vars->win, 10, *y_pos, color, buffer);
	*y_pos += 20;
}
