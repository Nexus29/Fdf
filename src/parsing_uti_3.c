/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_uti_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:34:11 by glancell          #+#    #+#             */
/*   Updated: 2025/03/05 20:56:10 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(t_map *map, int fd)
{
	char	*line;
	char	**split;
	int		y;
	char	*nl;

	y = 0;
	line = get_next_line(fd);
	while (line && y < map->height)
	{
		nl = ft_strchr(line, '\n');
		if (nl)
			*nl = '\0';
		split = ft_split(line, ' ');
		if (!split)
		{
			free(line);
			return ;
		}
		process_split_line(map, split, y);
		free_split(split);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	process_remaining_lines(map, y);
}

int	allocate_rows(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		map->matrix[i] = (int *)malloc(sizeof(int) * map->width);
		map->colors[i] = (int *)malloc(sizeof(int) * map->width);
		if (!map->colors[i] || !map->matrix[i])
		{
			free_map(map);
			return (0);
		}
		j = 0;
		while (j < map->width)
		{
			map->matrix[i][j] = 0;
			map->colors[i][j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
	return (1);
}

int	allocate_matrix(t_map *map)
{
	int	i;

	if (!map)
		return (0);
	map->matrix = (int **)malloc(sizeof(int *) * map->height);
	if (!map->matrix)
		return (0);
	i = 0;
	while (i < map->height)
		map->matrix[i++] = NULL;
	map->colors = (int **)malloc(sizeof(int *) * map->height);
	if (!map->colors)
	{
		free_map(map);
		return (0);
	}
	i = 0;
	while (i < map->height)
		map->colors[i++] = NULL;
	return (allocate_rows(map));
}
