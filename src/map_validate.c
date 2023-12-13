/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:31 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 15:03:30 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	terminate_perror(char *msg, int errnum)
{
	if (errnum != 0)
		errno = errnum;
	perror(msg);
	exit(EXIT_FAILURE);
}

void	file_name_validate(char *arg)
{
	char	*ptr;

	ptr = ft_strrchr(arg, '.');
	if (ft_strncmp(ptr, ".ber\0", 5))
		terminate_perror("Error\nFile name is invalid, *.ber is expected", 22);
}

void	map_texture_validate(char **map)
{
	int	pfg;
	int	efg;

	pfg = 0;
	efg = 0;
	while (*map)
	{
		if (!(*map == '1' || *map == '0' || *map == 'E' || *map == 'C'
				|| *map == 'P' || *map == '\n'))
			terminate_perror("Error\nMap contains invalid charecter", 22);
		if (*map == 'P')
			pfg++;
		if (*map == 'E')
			efg++;
		map++;
	}
	if (pfg != 1 || efg != 1)
		terminate_perror("Error\nMap must has only one P and E", 22);
}

void	map_shape_validate(char *map)
{
	int	width;
	int	tmp;

	width = 0;
	tmp = 0;
	while (*map)
	{
		if (*map == '\n')
		{
			if (tmp == 0)
				tmp = width;
			if (tmp != width)
				terminate_perror("Error\nMap must be rectangle", 22);
			width = 0;
		}
		else
			width++;
		map++;
	}
	if (tmp != width)
		terminate_perror("Error\nMap must be rectangle", 22);
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

void	map_playable_validate(t_map_info map_info)
{
	if (map_info.width <= 2 || map_info.height <= 2)
		terminate_perror("Error\nMap is too narrow", 22);
	if (map_info.collectible_count < 1)
		terminate_perror("Error\nMap must has at least one 'C'", 22);
	map_texture_validate(map_info.map);
	correct_wall_validate(map_info);
}

