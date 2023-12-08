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