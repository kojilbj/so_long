#include "./minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	close_handler(int keycode, t_vars *vars)
{
	printf("keycode = %d\n", keycode);
	if(keycode == 65307)
	{
		printf("mlx: %d\n", mlx_destroy_window(vars->mlx, vars->win));
		exit(1);
	}
}

int	main(void)
{
	t_vars	vars1;
	vars.mlx = mlx_init();

	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "Hello World");
	int	w, h;
	w = 0;
	h = 0;
/*	while(w < 1080)
	{
		h = 0;
		while(h < 1080)
		{
			mlx_pixel_put(mlx, mlx_window, w, h, 0xff0000);
			h++;
		}
		w++;
	}
	*/
	int	img_width;
	int	img_height;
	void	*img;
	img = mlx_xpm_file_to_image(vars.mlx, "./image.xpm", &img_width, &img_height);
	if(img == NULL)
		printf("NULL\n");
	else
		printf("%x\n", img);
	printf("width=%d\nheight=%d\n", img_width, img_height);
	mlx_string_put(vars.mlx, vars.win, 10, 10, 0x0000FF00, "Hello World!Hello World!");
	mlx_put_image_to_window(vars.mlx, vars.win, img, 1080 / 4, 1080 / 4);
	mlx_key_hook(vars.win, close_handler, &vars);
	mlx_loop(vars.mlx);
	return 0;
}
