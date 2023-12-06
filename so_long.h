#ifndef SO_LONG_H
#define SO_LONG_H

//#include "./minilibx/mlx.h"
#include <mlx.h>
#include "./libft/libft.h"
#include <fcntl.h>

#define PANEL_SIZE 64

typedef struct	s_image_info {
	char	texture;
	void	*img;
}	t_image_info;

typedef struct	s_map_info {
	char	*map_file_path;
	t_image_info	**map;
	int	width;
	int	height;
	int	collectible;
}	t_map_info;

typedef struct s_vars {
	void	*win;
	void	*mlx;
}	t_vars;

typedef struct	s_player_info {
	int	curr_x;
	int	curr_y;
	int	move_count;
}	t_player_info;

//map_validate.c
void	map_texture_validate(char *map);
void	map_shape_validate(char *map);
void	map_validate(char *map);
void	correct_wall_validate(t_map_info map_info);
void	map_playable_validate(char *map, t_map_info map_info);

//get_map.c
void	get_map_info(t_map_info *map_info, char *map);
t_image_info	**get_z_dimention_map(t_map_info *map_info, char *map);
char	*get_map_as_line(char	*file_path);

//create_map.c
void	create_window(t_vars *vars, t_map_info map_info);
void	mapping_background(t_vars vars, t_map_info map_info);

#endif
