/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:47 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 11:17:48 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_free(char **z_dimention_map)
{
	int	i;

	i = 0;
	while (z_dimention_map[i])
	{
		free(z_dimention_map[i]);
		i++;
	}
}

int	terminate_program(t_vars vars, char *msg, int errnum)
{
	if (errnum != 0)
		errno = errnum;
	if (msg != NULL)
		perror(msg);
	if (vars.mlx != NULL)
		mlx_destroy_window(vars.mlx, vars.win);
	if (vars.map_info.map_line != NULL)
		free(vars.map_info.map_line);
	if (vars.map_info.map != NULL)
		map_free(vars.map_info.map);
	if (vars.map_imgs.background != NULL)
		mlx_destroy_image(vars.mlx, vars.map_imgs.background);
	if (vars.map_imgs.collectible != NULL)
		mlx_destroy_image(vars.mlx, vars.map_imgs.collectible);
	if (vars.map_imgs.exit != NULL)
		mlx_destroy_image(vars.mlx, vars.map_imgs.exit);
	if (vars.map_imgs.player != NULL)
		mlx_destroy_image(vars.mlx, vars.map_imgs.player);
	if (vars.map_imgs.wall != NULL)
		mlx_destroy_image(vars.mlx, vars.map_imgs.wall);
	if (vars.mlx != NULL)
		free(vars.mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	exit_check(t_vars vars)
{
	int		collected;
	int		collectibles;
	int		x;
	int		y;
	char	letter;

	collected = vars.player_info.collect_count;
	collectibles = vars.map_info.collectible_count;
	x = vars.player_info.curr_x;
	y = vars.player_info.curr_y;
	letter = vars.map_info.map[y][x];
	if (letter == 'E' && collected == collectibles)
		return (1);
	return (0);
}
