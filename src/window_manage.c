/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:14 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 17:54:47 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reflesh_window_util(int x, int y, t_vars vars)
{
	int			curr_x;
	int			curr_y;
	int			last_x;
	int			last_y;
	t_map_imgs	imgs;

	imgs = vars.map_imgs;
	curr_x = vars.player_info.curr_x * PANEL_SIZE;
	curr_y = vars.player_info.curr_y * PANEL_SIZE;
	last_x = (vars.player_info.curr_x + x) * PANEL_SIZE;
	last_y = (vars.player_info.curr_y + y) * PANEL_SIZE;
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.player, curr_x, curr_y);
	mlx_put_image_to_window(vars.mlx, vars.win, imgs.background, last_x,
		last_y);
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
