/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:20 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 14:51:22 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_map_info(t_vars *vars, char *map)
{
	vars->map_info.width = 0;
	vars->map_info.height = 0;
	vars->map_info.collectible_count = 0;
	while (*map)
	{
		if (*map == 'C')
			vars->map_info.collectible_count++;
		if (*map == 'E')
		{
			vars->map_info.exit_x = vars->map_info.width;
			vars->map_info.exit_y = vars->map_info.height;
		}
		if (*map == '\n')
		{
			vars->map_info.height++;
			vars->map_info.width = 0;
		}
		else
			vars->map_info.width++;
		map++;
	}
	vars->map_info.height++;
}

void	set_map_imgs(t_vars *vars)
{
	int			tmp;
	void		*mlx;
	t_map_imgs	*map_imgs;

	mlx = vars->mlx;
	map_imgs = &vars->map_imgs;
	map_imgs->player = mlx_xpm_file_to_image(mlx, "map/player.xpm", &tmp,
		&tmp);
	map_imgs->exit = mlx_xpm_file_to_image(mlx, "map/exit.xpm", &tmp,
		&tmp);
	map_imgs->collectible = mlx_xpm_file_to_image(mlx, "map/collectible.xpm",
		&tmp, &tmp);
	map_imgs->background = mlx_xpm_file_to_image(mlx, "map/background.xpm",
		&tmp, &tmp);
	map_imgs->wall = mlx_xpm_file_to_image(mlx, "map/wall.xpm", &tmp,
		&tmp);
	if(!(map_imgs->player && map_imgs->exit && map_imgs->collectible && map_imgs->background && map_imgs->wall))
	{
		perror("Error\nmlx_xpm_file_to_image");
		terminate_program(vars);
	}
}

char	*get_map_as_line(char *file_path)
{
	int		i;
	int		fd;
	char	buff[10];
	char	*tmp;
	char	*map_line;

	map_line = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		terminate_perror("Error\nopen", 0);
	while (1)
	{
		i = read(fd, buff, 9);
		if (i == 0)
			break ;
		buff[i] = '\0';
		tmp = map_line;
		map_line = ft_strjoin(map_line, buff);
		free(tmp);
	}
	close(fd);
	return (map_line);
}

char	**get_z_dimention_map(char *map)
{
	char	**z_dimention_map;

	z_dimention_map = ft_split(map, '\n');
	if(z_dimention_map == NULL)
		terminate_perror("Error\nft_split", 0);
	return z_dimention_map;
}
