/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:14 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 14:49:20 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reflesh_window_util(int x, int y, t_vars vars)
{
	int	curr_x;
	int	curr_y;
	int	last_x;
	int	last_y;
	t_map_imgs	imgs;

	imgs = vars.map_imgs;
	curr_x = vars.player_info.curr_x * PANEL_SIZE;
	curr_y = vars.player_info.curr_y * PANEL_SIZE;
	last_x = (vars.player_info.curr_x + x) * PANEL_SIZE;
	last_y = (vars.player_info.curr_y + y) * PANEL_SIZE;
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.player, curr_x, curr_y);
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.background, last_x, last_y);
}

void	reflesh_window(int direction, t_vars vars)
{
	if (direction == UP)
		reflesh_window_util(0, 1, vars);
	if (direction == DOWN)
		reflesh_window_util(0, -1, vars);
	if (direction == RIGHT)
		reflesh_window_util(-1, 0, vars);
	if (direction == LEFT)
		reflesh_window_util(+1, 0, vars);
}

void	move_player(int direction, t_vars *vars)
{
	if (direction == UP)
		vars->player_info.curr_y -= 1;
	if (direction == DOWN)
		vars->player_info.curr_y += 1;
	if (direction == RIGHT)
		vars->player_info.curr_x += 1;
	if (direction == LEFT)
		vars->player_info.curr_x -= 1;
}

int	move_player_check(int keycode, t_vars vars)
{
	int	x;
	int	y;

	x = vars.player_info.curr_x;
	y = vars.player_info.curr_y;
	if (keycode == 119 || keycode == 65362)
	{
		if (vars.map_info.map[y - 1][x] != '1')
			return (UP);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		if (vars.map_info.map[y + 1][x] != '1')
			return (DOWN);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		if (vars.map_info.map[y][x + 1] != '1')
			return (RIGHT);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		if (vars.map_info.map[y][x - 1] != '1')
			return (LEFT);
	}
	return (0);
}
