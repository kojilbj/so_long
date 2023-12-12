#include "../so_long.h"

void	reflesh_window(int direction, t_vars  vars)
{
	int	x;
	int	y;

	x = vars.player_info.curr_x;
	y = vars.player_info.curr_y;
	if(direction == UP)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.player, x * PANEL_SIZE, y * PANEL_SIZE); 
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.background, x * PANEL_SIZE, (y + 1) * PANEL_SIZE); 
	}
	if(direction == DOWN)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.player, x * PANEL_SIZE, y * PANEL_SIZE); 
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.background, x * PANEL_SIZE, (y - 1) * PANEL_SIZE); 
	}
	if(direction == RIGHT)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.player, x * PANEL_SIZE, y * PANEL_SIZE); 
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.background, (x - 1) * PANEL_SIZE, y * PANEL_SIZE); 
	}
	if(direction == LEFT)
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.player, x * PANEL_SIZE, y * PANEL_SIZE); 
		mlx_put_image_to_window(vars.mlx, vars.win, vars.map_imgs.background, (x + 1) * PANEL_SIZE, y * PANEL_SIZE); 
	}
}

void	move_player(int direction, t_vars *vars)
{
	if(direction == UP)
		vars->player_info.curr_y -= 1;
	if(direction == DOWN)
		vars->player_info.curr_y += 1;
	if(direction == RIGHT)
		vars->player_info.curr_x += 1;
	if(direction == LEFT)
		vars->player_info.curr_x -= 1;
}

int	move_player_check(int keycode, t_vars *vars)
{
	if(keycode == 119 || keycode == 65362)
	{
		if(vars->map_info.map[vars->player_info.curr_y - 1][vars->player_info.curr_x].texture != '1')
			return UP;
	}
	else if(keycode == 115 || keycode == 65364)
	{
		if(vars->map_info.map[vars->player_info.curr_y + 1][vars->player_info.curr_x].texture != '1')
			return DOWN;
	}
	else if(keycode == 100 || keycode == 65363)
	{
		if(vars->map_info.map[vars->player_info.curr_y][vars->player_info.curr_x + 1].texture != '1')
			return RIGHT;
	}
	else if(keycode == 97 || keycode == 65361)
	{
		if(vars->map_info.map[vars->player_info.curr_y][vars->player_info.curr_x - 1].texture != '1')
			return LEFT;
	}
	return 0;
}
