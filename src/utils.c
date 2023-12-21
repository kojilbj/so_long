/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:25:59 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 11:36:10 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_imgs_setempty(t_vars *vars)
{
	t_map_imgs	*imgs;

	imgs = &vars->map_imgs;
	imgs->player = NULL;
	imgs->exit = NULL;
	imgs->collectible = NULL;
	imgs->background = NULL;
	imgs->wall = NULL;
}

void	vars_setempty(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map_info.map = NULL;
	vars->map_info.map_line = NULL;
	map_imgs_setempty(vars);
}
