/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:14 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 17:17:06 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(int direction, t_vars *vars)
{
	t_player_info *player;

	player = &vars->player_info;
	if (direction == UP)
		player->curr_y -= 1;
	if (direction == DOWN)
		player->curr_y += 1;
	if (direction == RIGHT)
		player->curr_x += 1;
	if (direction == LEFT)
		player->curr_x -= 1;
}

int	move_player_check(int keycode, t_vars vars)
{
	if (keycode == 119 || keycode == 65362)
	{
		if (vars.map_info.map[vars.player_info.curr_y - 1]
			[vars.player_info.curr_x] != '1')
			return (UP);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		if (vars.map_info.map[vars.player_info.curr_y
				+ 1][vars.player_info.curr_x] != '1')
			return (DOWN);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		if (vars.map_info.map[vars.player_info.curr_y][vars.player_info.curr_x
			+ 1] != '1')
			return (RIGHT);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		if (vars.map_info.map[vars.player_info.curr_y][vars.player_info.curr_x
			- 1] != '1')
			return (LEFT);
	}
	return (0);
}
