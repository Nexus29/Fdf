/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:00:46 by glancell          #+#    #+#             */
/*   Updated: 2025/03/05 20:20:01 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_point(char *str, int *height, int *color)
{
	char	**values;

	*color = 0xFFFFFF;
	if (!str)
	{
		*height = 0;
		return (0);
	}
	if (ft_strchr(str, ','))
	{
		values = ft_split(str, ',');
		if (!values)
			return (0);
		*height = ft_atoi(values[0]);
		if (values[1] && ft_strncmp(values[1], "0x", 2) == 0)
			*color = ft_atoi_base(values[1] + 2, 16);
		free_split(values);
	}
	else
		*height = ft_atoi(str);
	return (1);
}

static int	open_file_safely(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: Unable to open file\n", 27);
		return (-1);
	}
	return (fd);
}

static int	validate_map_dimensions(t_map *map)
{
	if (map->height <= 0)
	{
		write(2, "Error: Invalid map height\n", 26);
		return (0);
	}
	if (map->width <= 0)
	{
		write(2, "Error: Invalid map width\n", 26);
		return (0);
	}
	return (1);
}

static int	prepare_map_data(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open_file_safely(file);
	if (fd < 0)
		return (0);
	map->height = get_map_height(file);
	gnl_clear_fd(fd);
	close(fd);
	fd = open_file_safely(file);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	gnl_clear_fd(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	map->width = get_map_width(line);
	free(line);
	close(fd);
	return (validate_map_dimensions(map));
}

int	parse_map(char *file, t_map *map)
{
	int	fd;

	if (!file || !map)
		return (0);
	if (!prepare_map_data(file, map))
		return (0);
	if (!allocate_matrix(map))
		return (0);
	fd = open_file_safely(file);
	if (fd < 0)
	{
		free_map(map);
		return (0);
	}
	fill_map(map, fd);
	gnl_clear_fd(fd);
	close(fd);
	return (1);
}
