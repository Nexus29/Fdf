/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_uti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:57:03 by glancell          #+#    #+#             */
/*   Updated: 2025/03/04 21:01:48 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	digit;

	result = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		str++;
	}
	return (result);
}

int	count_elements(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	process_split_line(t_map *map, char **split, int y)
{
	int	x;
	int	height;
	int	color;

	x = 0;
	while (split[x] && x < map->width)
	{
		if (split[x][0] != '\0')
		{
			if (parse_point(split[x], &height, &color))
			{
				map->matrix[y][x] = height;
				map->colors[y][x] = color;
			}
		}
		else
		{
			map->matrix[y][x] = 0;
			map->colors[y][x] = 0xFFFFFF;
		}
		x++;
	}
}

void	process_remaining_lines(t_map *map, int start_y)
{
	int	y;
	int	x;

	y = start_y;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->matrix[y][x] = 0;
			map->colors[y][x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
}
