/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan < kojwatan@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:59:34 by kojwatan          #+#    #+#             */
/*   Updated: 2023/12/21 11:33:47 by kojwatan         ###   ########.fr       */
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
# define ESC 65307

typedef struct s_map_imgs
{
	void			*player;
	void			*exit;
	void			*collectible;
	void			*background;
	void			*wall;
}				t_map_imgs;

typedef struct s_map_info
{
	char	**map;
	char	*map_line;
	int		width;
	int		height;
	int		exit_x;
	int		exit_y;
	int		collectible_count;
}			t_map_info;

typedef struct s_player_info
{
	int				curr_x;
	int				curr_y;
	int				collect_count;
	int				move_count;
}					t_player_info;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_map_imgs		map_imgs;
	t_map_info		map_info;
	t_player_info	player_info;
}					t_vars;

// map_validate.c
void				map_letter_validate(t_vars vars);
int					map_shape_validate(char *map);
void				correct_wall_validate(t_vars vars);
void				map_playable_validate(t_vars vars);

//map_path_validate.c
int					file_name_validate(char *arg);
void				map_path_validate(t_vars vars);

// map_info.c
void				get_map_info(t_vars *vars, char *map);
char				**get_z_dimention_map(t_vars vars, char *map);
char				*map_file_to_line(t_vars vars, char *file_path);
void				set_map_imgs(t_vars *vars);

// display_map.c
void				create_window(t_vars *vars);
void				mapping_background(t_vars vars);
void				put_map_to_window(t_vars vars);

// get_player_info.c
void				get_player_info(t_vars *vars);
void				move_count(int move_direcion, t_vars *vars);
void				collect_count(t_vars *vars);

// control_player.c
void				move_player(int direction, t_vars *vars);
int					move_player_check(int keycode, t_vars vars);

//window_manage.c
void				reflesh_window(int direction, t_vars vars);

// terminate.c
void				map_free(char **z_dimention_map);
int					terminate_program(t_vars vars, char *msg, int errnum);
int					exit_check(t_vars vars);

//utils.c
void				map_imgs_setempty(t_vars *vars);
void				vars_setempty(t_vars *vars);

#endif
