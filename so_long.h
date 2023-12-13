/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:34 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/13 14:59:07 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

# define PANEL_SIZE 64
# define UP 1
# define DOWN 2
# define RIGHT 3
# define LEFT 4

typedef struct s_map_imgs
{
	void			*player;
	void			*exit;
	void			*collectible;
	void			*background;
	void			*wall;
}					t_map_imgs;

typedef struct s_map_info
{
	char	**map;
	int				width;
	int				height;
	int				exit_x;
	int				exit_y;
	int				collectible_count;
}					t_map_info;

typedef struct s_player_info
{
	int				curr_x;
	int				curr_y;
	int				collect_count;
	int				move_count;
}					t_player_info;

typedef struct s_vars
{
	void			*win;
	void			*mlx;
	t_map_info		map_info;
	t_player_info	player_info;
	t_map_imgs		map_imgs;
}					t_vars;

// map_validate.c
void				terminate_perror(char *msg, int errnum);
void				file_name_validate(char *arg);
void				map_texture_validate(char *map);
void				map_shape_validate(char *map);
void				correct_wall_validate(t_map_info map_info);
void				map_playable_validate(char *map, t_map_info map_info);

// get_map.c
void				get_map_info(t_vars *vars, char *map);
char				**get_z_dimention_map(char *map);
char				*get_map_as_line(char *file_path);
void				set_map_imgs(t_vars *vars);

// display_map.c
void				create_window(t_vars *vars);
void				mapping_background(t_vars vars);
void				put_map_to_window(t_vars vars);

// get_player_info.c
t_player_info		get_player_info(t_map_info map_info);
void				move_count(int move_direcion, t_vars *vars);
void				collect_count(t_vars *vars);

// control_player.c
void				reflesh_window(int direction, t_vars vars);
void				move_player(int direction, t_vars *vars);
int					move_player_check(int keycode, t_vars vars);

// terminate.c
void				map_free(char **z_dimention_map);
int					terminate_program(t_vars *vars);
int					exit_check(t_vars vars);

#endif
