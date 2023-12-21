/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:31 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 13:31:06 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map, t_vars vars, int x, int y)
{
	int	width;
	int	height;

	width = vars.map_info.width;
	height = vars.map_info.height;
	if (x < 0 || y < 0 || x > width || y > height || map[y][x] == 'F')
		return ;
	if (map[y][x] == '1')
		return ;
	map[y][x] = 'F';
	flood_fill(map, vars, x + 1, y);
	flood_fill(map, vars, x - 1, y);
	flood_fill(map, vars, x, y + 1);
	flood_fill(map, vars, x, y - 1);
}

void	map_path_validate(t_vars vars)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = ft_split(vars.map_info.map_line, '\n');
	if (map_dup == NULL)
		terminate_program(vars, "Error\nft_split", 0);
	flood_fill(map_dup, vars, vars.player_info.curr_x, vars.player_info.curr_y);
	while (map_dup[i])
	{
		if (ft_strchr(map_dup[i], 'P')
			|| ft_strchr(map_dup[i], 'E')
			|| ft_strchr(map_dup[i], 'C'))
		{
			map_free(map_dup);
			terminate_program(vars, "Error\nMap doesn't have path", 22);
		}
		i++;
	}
	map_free(map_dup);
}

int	file_name_validate(char *arg)
{
	char	*ptr;

	if (ft_strlen(arg) < 5)
		return (1);
	ptr = ft_strrchr(arg, '.');
	if (ft_strncmp(ptr, ".ber\0", 5))
		return (1);
	return (0);
}
