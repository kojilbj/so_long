/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:28 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/12 17:01:16 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook_handler(int keycode, t_vars *vars)
{
	int	move_direction;

	if (keycode == 65307)
		terminate_program(vars);
	move_direction = move_player_check(keycode, vars);
	move_player(move_direction, vars);
	move_count(move_direction, vars);
	reflesh_window(move_direction, *vars);
	collect_count(vars);
	if (exit_check(*vars))
		terminate_program(vars);
	return (1);
}

int	main(int ac, char *av[])
{
	t_vars	vars;
	char	*map;

	if (ac != 2)
		terminate_perror("Error\nplease exec with *.ber map", 22);
	file_name_validate(av[1]);
	map = get_map_as_line(av[1]);
	map_shape_validate(map);
	get_map_info(&vars, map);
	vars.map_info.map = get_z_dimention_map(&vars.map_info, map);
	map_playable_validate(map, vars.map_info);
	free(map);
	create_window(&vars);
	set_map_imgs(&vars);
	mapping_background(vars);
	image_into_map(&vars);
	put_map_to_window(vars);
	vars.player_info = get_player_info(vars.map_info);
	mlx_hook(vars.win, 2, 1L << 0, key_hook_handler, &vars);
	mlx_hook(vars.win, 17, 1 << 17, terminate_program, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
