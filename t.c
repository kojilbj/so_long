#include "./so_long.h"
#include "minilibx/mlx.h"
/*
typedef struct	s_sd
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_sd;

int	key_handler(int keycode, t_sd *vars)
{
	printf("a\n");
	mlx_destroy_image(vars->mlx, vars->img);
	sleep(1);
	return 1;
}


int	main(void)
{
	t_sd	vars;
	int	i;
	int	j;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "test");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./map/wall.xpm", &i, &j);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_handler, &vars);
	mlx_loop(vars.mlx);
	return 0;
}*/
#include "./so_long.h"
#include "minilibx/mlx.h"

typedef struct s_sd
{
    void *mlx;
    void *win;
    void *img;
} t_sd;

int key_handler(int keycode, t_sd *vars)
{
        printf("Space key pressed\n");

        // 画像を破棄
        mlx_destroy_image(vars->mlx, vars->img);
	mlx_clear_window(vars->mlx, vars->win);
        // 画像を破棄した後、新しい画像を表示するか、何も表示しないか選択
        // 例: mlx_put_image_to_window(vars->mlx, vars->win, new_img, 0, 0);

    return 0;
}

int main(void)
{
    t_sd vars;
    int i, j;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "test");
    vars.img = mlx_xpm_file_to_image(vars.mlx, "./map/wall.xpm", &i, &j);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

    mlx_hook(vars.win, 2, 1L << 0, key_handler, &vars);
    mlx_loop(vars.mlx);

    return 0;
}

