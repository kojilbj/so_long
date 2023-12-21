/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:31 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 10:20:24 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_letter_validate_util(char c, int *pfg, int *efg)
{
	if (!(c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P'
			|| c == '\n'))
		terminate_perror("Error\nMap contains invalid letter", 22);
	if (c == 'P')
		(*pfg)++;
	if (c == 'E')
		(*efg)++;
}

void	map_letter_validate(char **map)
{
	int		x;
	int		y;
	int		pfg;
	int		efg;
	char	c;

	x = 0;
	y = 0;
	pfg = 0;
	efg = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			map_letter_validate_util(c, &pfg, &efg);
			x++;
		}
		y++;
	}
	if (pfg != 1 || efg != 1)
		terminate_perror("Error\nMap must has only one P and E", 22);
}

int	map_shape_validate(char *map)
{
	int	width;
	int	tmp;
	int	i;

	width = 0;
	tmp = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (tmp == 0)
				tmp = width;
			if (tmp != width)
				return 1;
			width = 0;
		}
		else
			width++;
		i++;
	}
	if (tmp != width)
		return 1;
}

void	correct_wall_validate(t_map_info map_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if (y == 0 || y == map_info.height - 1 || x == 0
				|| x == map_info.width - 1)
			{
				if (map_info.map[y][x] != '1')
					terminate_perror("Error\nMap must surrounded by '1'", 22);
			}
			x++;
		}
		y++;
	}
}

void	map_playable_validate(char *map_line, t_vars vars)
{
	if (vars.map_info.width <= 2 || vars.map_info.height <= 2)
	{
		free_map(vars.map_info.map);
		terminate_perror("Error\nMap is too narrow", 22, vars.map_line);
	}
	if (vars.map_info.collectible_count < 1)
	{
		free_map(vars.map_indo.map);
		terminate_perror("Error\nMap must has at least one 'C'", 22, vars.map_line);
	}
	map_letter_validate(vars.map_info.map);
	correct_wall_validate(vars.map_info);
	map_path_validate(map_line, vars);
}
