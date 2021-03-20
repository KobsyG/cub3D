#include "mlx/mlx.h"
#include "cub3D.h"
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int				key_hook(int keycode, t_vars *vars)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// }

// int				main(void)
// {
// 	t_vars	vars;
// 	int		fd;
// 	t_map	info_map;
// 	int		i;
// 	int		j;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	fd = open("map.cub", O_RDONLY);
// 	printf("yes = %d\n", ID_map(fd, &info_map));
// 	i = -1;
// 	while (++i < 480)
// 	{
// 		j = -1;
// 		while (++j < 640)
// 			mlx_pixel_put(vars.mlx, vars.win, j, i, info_map.color_F);
// 	}
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }


int main()
{
	int		fd;
	int 	i;
	t_map	info_map;

	fd = open("map.cub", O_RDONLY);
	printf("yes = %d\n", ID_map(fd, &info_map));
	printf("x = |%d|\ny = |%d|\npath_NO = |%s|\npath_SO = |%s|\n", info_map.x, info_map.y, info_map.path_NO, info_map.path_SO);
	printf("path_WE = |%s|\npath_EA = |%s|\npath_S = |%s|\n", info_map.path_WE, info_map.path_EA, info_map.path_S);
	printf("color_F = |%d|\ncolor_C = |%d|\n", info_map.color_F, info_map.color_C);
	printf("yes2 = %d\n\n", descr_map(fd, &info_map));

	i = 0;
	while (info_map.map[i])
	{
		printf("map[%d] = |%s|\n", i, info_map.map[i]);
		i++;
	}
	while (1);
	return (0);
}
