/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_uti_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:02:58 by glancell          #+#    #+#             */
/*   Updated: 2025/03/05 21:10:59 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gnl_clear_fd(int fd)
{
	static char	*string[4096];

	if (fd >= 0 && fd < 4096 && string[fd] != NULL)
	{
		free(string[fd]);
		string[fd] = NULL;
	}
}

int	get_map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	if (!file)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_map_width(char *line)
{
	char	**split;
	int		width;
	int		i;
	char	*nl;

	nl = ft_strchr(line, '\n');
	if (nl)
		*nl = '\0';
	split = ft_split(line, ' ');
	if (!split)
		return (-1);
	width = 0;
	i = 0;
	while (split[i])
	{
		if (split[i][0] != '\0')
			width++;
		i++;
	}
	free_split(split);
	return (width);
}

void	free_mlx(t_vars *vars)
{
	if (!vars)
		return ;
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
		vars->mlx = NULL;
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->matrix)
	{
		i = 0;
		while (i < map->height)
			free(map->matrix[i++]);
		free(map->matrix);
		map->matrix = NULL;
	}
	if (map->colors)
	{
		i = 0;
		while (i < map->height)
			free(map->colors[i++]);
		free(map->colors);
		map->colors = NULL;
	}
}
