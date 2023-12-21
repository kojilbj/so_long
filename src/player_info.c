/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:24 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 11:23:55 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_info(t_vars *vars)
{
	int				x;
	int				y;
	t_map_info		map_info;

	map_info = vars->map_info;
	x = 0;
	y = 0;
	while (y < map_info.height)
	{
		x = 0;
		while (x < map_info.width)
		{
			if (map_info.map[y][x] == 'P')
			{
				vars->player_info.curr_x = x;
				vars->player_info.curr_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	vars->player_info.collect_count = 0;
	vars->player_info.move_count = 0;
}

void	move_count(int move_direction, t_vars *vars)
{
	if (move_direction)
	{
		vars->player_info.move_count++;
		ft_printf("player has moved %d times\n", vars->player_info.move_count);
	}
}

void	collect_count(t_vars *vars)
{
	char	**map;
	int		x;
	int		y;

	map = vars->map_info.map;
	x = vars->player_info.curr_x;
	y = vars->player_info.curr_y;
	if (map[y][x] == 'C')
	{
		vars->player_info.collect_count++;
		map[y][x] = '0';
	}
}
