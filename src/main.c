/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:56:21 by glancell          #+#    #+#             */
/*   Updated: 2025/03/06 01:18:32 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	extension_check(char *av);
static void	init_camera(t_camera *camera);
static int	init_mlx_resources(t_vars *vars);
static void	setup_hooks(t_vars *vars);

int	main(int ac, char **av)
{
	t_vars	vars;
	t_map	map;

	if (ac != 2 || !extension_check(av[1]) || !parse_map(av[1], &map))
	{
		write(1, "Wrong usage or map parsing failed\n", 35);
		return (1);
	}
	if (!init_mlx_resources(&vars))
	{
		free_map(&map);
		return (1);
	}
	vars.map = &map;
	init_camera(&vars.camera);
	vars.show_menu = 1;
	draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	if (vars.show_menu)
		render_menu(&vars);
	setup_hooks(&vars);
	mlx_loop(vars.mlx);
	free_mlx_resources(&vars);
	free_map(&map);
	return (0);
}

static int	init_mlx_resources(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars->img_addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!vars->img_addr || !vars->img || !vars->win)
	{
		free_mlx_resources(vars);
		return (0);
	}
	return (1);
}

static void	setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
}

static void	init_camera(t_camera *camera)
{
	camera->alpha = 0.0f;
	camera->beta = 0.0f;
	camera->gamma = 0.0f;
	camera->zoom = 1.0f;
	camera->z_scale = 0.1f;
	camera->x_offset = 0.0f;
	camera->y_offset = 0.0f;
	camera->projection = 0;
}

static int	extension_check(char *av)
{
	int		l;
	int		i;
	char	*str;

	l = 0;
	i = 3;
	str = ".fdf";
	while (av[l + 1] != '\0')
		l++;
	while (i >= 0)
	{
		if (av[l] != str[i])
			return (0);
		l--;
		i--;
	}
	return (1);
}
