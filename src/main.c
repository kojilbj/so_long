#include "../so_long.h"
#include <stdio.h>

int	key_hook_handler(int keycode, t_vars *vars)
{
	t_image_info **map;
	int	move_direction;

	map = vars->map_info.map;
	move_direction = move_player_check(keycode, vars);
	move_player(move_direction, vars);
	move_count(move_direction, vars);
	reflesh_window(move_direction, *vars);
	collect_count(vars);
	if(map[vars->player_info.curr_y][vars->player_info.curr_x].texture == 'E' && vars->player_info.collect_count == vars->map_info.collectible_count)
		mlx_destroy_window(vars->mlx, vars->win);
	if(map[vars->player_info.curr_y][vars->player_info.curr_x].texture != 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->map_imgs.exit, vars->map_info.exit_x * PANEL_SIZE, vars->map_info.exit_y * PANEL_SIZE);
	return 1;
}

int	main(int ac, char *av[])
{
	t_vars	vars;
	char	*map;
	if(ac != 2)
	{
		ft_printf("Invalid argument\n");
		return 0;
	}
	map = get_map_as_line(av[1]);
	map_shape_validate(map);
	get_map_info(&vars, map);
	vars.map_info.map = get_z_dimention_map(&vars.map_info, map);
	map_playable_validate(map, vars.map_info);
	create_window(&vars, vars.map_info);
	set_map_imgs(&vars);
	mapping_background(vars, &vars.map_info);
	image_into_map(&vars);
	put_map_to_window(vars);
	vars.player_info = get_player_info(vars.map_info);
	mlx_hook(vars.win, 2, 1L<<0, key_hook_handler, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
