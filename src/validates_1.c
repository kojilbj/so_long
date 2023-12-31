/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:31 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 11:20:39 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_letter_validate_util(t_vars vars, char c, int *pfg, int *efg)
{
	if (!(c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P'
			|| c == '\n'))
		terminate_program(vars, "Error\nMap contains invalid letter", 22);
	if (c == 'P')
		(*pfg)++;
	if (c == 'E')
		(*efg)++;
}

void	map_letter_validate(t_vars vars)
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
	while (vars.map_info.map[y])
	{
		x = 0;
		while (vars.map_info.map[y][x])
		{
			c = vars.map_info.map[y][x];
			map_letter_validate_util(vars, c, &pfg, &efg);
			x++;
		}
		y++;
	}
	if (pfg != 1 || efg != 1)
		terminate_program(vars, "Error\nMap must has only one P and E", 22);
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
				return (1);
			width = 0;
		}
		else
			width++;
		i++;
	}
	if (tmp != width)
		return (1);
	return (0);
}

void	correct_wall_validate(t_vars vars)
{
	int			x;
	int			y;
	t_map_info	map_info;

	x = 0;
	y = 0;
	map_info = vars.map_info;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if (y == 0 || y == map_info.height - 1 || x == 0
				|| x == map_info.width - 1)
			{
				if (map_info.map[y][x] != '1')
					terminate_program(vars,
						"Error\nMap must surrounded by '1'", 22);
			}
			x++;
		}
		y++;
	}
}

void	map_playable_validate(t_vars vars)
{
	if (vars.map_info.width <= 2 || vars.map_info.height <= 2)
		terminate_program(vars, "Error\nMap is too narrow", 22);
	if (vars.map_info.collectible_count < 1)
		terminate_program(vars, "Error\nMap must has at least one 'C'", 22);
	map_letter_validate(vars);
	correct_wall_validate(vars);
	map_path_validate(vars);
}
