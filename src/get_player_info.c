#include "../so_long.h"

t_player_info   get_player_info(t_map_info map_info)
{
    int i;
    int j;
    t_player_info   player_info;

    i = 0;
    j = 0;
    while(i < map_info.height)
    {
        j = 0;
        while (j < map_info.width)
        {
            if(map_info.map[i][j].texture == 'P')
            {
                player_info.curr_x = j;
                player_info.curr_y = i;
                break;
            }
            j++;
        }
        i++;
    }
    player_info.collect_count = 0;
    player_info.move_count = 0;
    return player_info;
}

void	move_count(int	move_direction, t_vars *vars)
{
	if(move_direction)
		vars->player_info.move_count++;
	ft_printf("player has moved %d times\n", vars->player_info.move_count);
}

void	collect_count(t_vars *vars)
{
	t_image_info **map;
	int	x;
	int	y;

	map = vars->map_info.map;
	x = vars->player_info.curr_x;
	y = vars->player_info.curr_y;
	if(map[y][x].texture == 'C')
	{
		vars->player_info.collect_count++;
		map[y][x].texture = '0';
	}
}
