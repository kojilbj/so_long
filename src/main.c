#include "../so_long.h"
#include <stdio.h>


int	key_hook_handler(int keycode, t_vars *vars)
{
	int	i;
	int	curr_x;
	int	curr_y;
	t_image_info **map;

	map = vars->map_info.map;
	curr_x = vars->player_info.curr_x;
	curr_y = vars->player_info.curr_y;
	printf("keycode %d\n", keycode);
	if(keycode == 65506)
	{
		ft_printf("up\n");
		if(map[curr_y - 1][curr_x].texture != '1')
			vars->player_info.curr_y -= 1;
		else
			ft_printf("invalid way\n");
	}
	else if(keycode == 65511)
	{
		ft_printf("down\n");
		if(map[curr_y + 1][curr_x].texture != '1')
			vars->player_info.curr_y += 1;
		else
			ft_printf("invalid way\n");
	}
	else if(keycode == 65512)
	{
		ft_printf("right\n");
		if(map[curr_y][curr_x + 1].texture != '1')
			vars->player_info.curr_x += 1;
		else
			ft_printf("invalid way\n");
	}
	else if(keycode == 65505)
	{
		ft_printf("left\n");
		if(map[curr_y][curr_x - 1].texture != '1')
			vars->player_info.curr_x -= 1;
		else
			ft_printf("invalid way\n");
	}
	if(map[vars->player_info.curr_y][vars->player_info.curr_x].texture == 'C')
	{
		ft_printf("Collectible\n");
		vars->player_info.collect_count++;
		vars->map_info.map[vars->player_info.curr_y][vars->player_info.curr_x].texture = '0';
		ft_printf("count: %d\n", vars->player_info.collect_count);
	}
	if(map[vars->player_info.curr_y][vars->player_info.curr_x].texture == 'E' && vars->player_info.collect_count == vars->map_info.collectible)
		ft_printf("EXIT\n");
	return 1;
}

int	main(int ac, char *av[])
{
	if(ac != 2)
	{
		ft_printf("Invalid argument\n");
		return 0;
	}
	t_map_info	map_info;
	char	*map = get_map_as_line(av[1]);
	map_shape_validate(map);
	get_map_info(&map_info, map);
	map_info.map = get_z_dimention_map(&map_info, map);
	map_playable_validate(map, map_info);
	t_vars	vars;
	create_window(&vars, map_info);
	mapping_background(vars, map_info);
	image_into_map(vars, &map_info);
	put_map_to_window(vars, map_info);
	vars.map_info = map_info;
	vars.player_info = get_player_info(map_info);
	mlx_hook(vars.win, 2, 1L<<0, key_hook_handler, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
