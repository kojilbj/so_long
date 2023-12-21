/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:28 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 13:37:58 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// #include <libc.h>
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q so_long");
// }

int	key_hook_handler(int keycode, t_vars *vars)
{
	int	move_direction;

	if (keycode == ESC)
		terminate_program(*vars, NULL, 0);
	move_direction = move_player_check(keycode, *vars);
	move_player(move_direction, vars);
	move_count(move_direction, vars);
	collect_count(vars);
	reflesh_window(move_direction, *vars);
	if (exit_check(*vars))
		terminate_program(*vars, NULL, 0);
	return (1);
}

void	validates(char *av, t_vars *vars)
{
	if (file_name_validate(av))
		terminate_program(*vars,
			"Error\nFile name is invalid, *.ber is expected", 22);
	vars->map_info.map_line = map_file_to_line(*vars, av);
	if (map_shape_validate(vars->map_info.map_line))
		terminate_program(*vars, "Error\nMap must be rectangle", 22);
	get_map_info(vars, vars->map_info.map_line);
	vars->map_info.map = get_z_dimention_map(*vars, vars->map_info.map_line);
	get_player_info(vars);
	map_playable_validate(*vars);
}

void	loop_hooks(t_vars vars)
{
	mlx_hook(vars.win, 2, 1L << 0, key_hook_handler, &vars);
	mlx_hook(vars.win, 17, 1 << 17, terminate_handler, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char *av[])
{
	t_vars	vars;

	vars_setempty(&vars);
	if (ac != 2)
		terminate_program(vars, "Error\tthis program needs a argument", 22);
	validates(av[1], &vars);
	create_window(&vars);
	set_map_imgs(&vars);
	mapping_background(vars);
	put_map_to_window(vars);
	loop_hooks(vars);
	return (0);
}
