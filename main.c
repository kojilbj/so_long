#include "./so_long.h"
#include <stdio.h>

int	key_hook_handler(int keycode, t_vars vars)
{
	printf("keycode %d\n", keycode);
	return 1;
}

int	main(int ac, char *av[])
{
	if(ac != 2)
		return 0;
	t_map_info	map_info;
	char	*map = get_map_as_line(av[1]);
	map_shape_validate(map);
	get_map_info(&map_info, map);
	map_info.map = get_z_dimention_map(&map_info, map);
	map_playable_validate(map, map_info);
	t_vars	vars;
	create_window(&vars, map_info);
	mapping_background(vars, map_info);
	mlx_hook(vars.win, 2, 1L<<0, key_hook_handler, &vars);
	mlx_loop(vars.mlx);
 	// int	i = 0;
	// int j = 0;
	// while(map_info.map[i])
	// {
	// 	while(map_info.map[i][j].texture != 'Z')
	// 	{
	// 		printf("%c", map_info.map[i][j].texture);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	printf("\n");
	// 	i++;
	// }
	// printf("%d", map_info.collectible);
	return 0;
}
