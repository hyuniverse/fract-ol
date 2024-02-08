#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color);
int		printimg();
int		exit_hook();
int		key_hook(int keycode, t_vars *vars);

int	main()
{
	printimg();
	return (0);
}

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int		exit_hook()
{
	exit(0);
}

int printimg()
{
	int		color;
	t_vars	vars;
	t_data	image;

	int img_width = 1920;
	int img_height = 1080;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, img_width, img_height, "fract-ol!");
	image.img = mlx_new_image(vars.mlx, img_width, img_height); //새로운 이미지 생성 
	//생성된 이미지에 대한 정보 리턴 (사용할 이미지 정보 넘겨서 색상 나타낼 때 필요한 비트수, 이미지 한 줄 저장 시 사용되는 바이트 수, 색상 저장 방식)
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	for (int i = 250, k = 99; i < 300; i++, k-=2)
	{
		for (int j = 150 + k; j < 250; j++)
		{
			double r = (double)(img_width - j) / (img_width - 1);
			double g = (double)(i) / (img_height - 1);
			double b = 1;
			color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) +((int)(255.999 * b));
			my_mlx_pixel_put(&image, i, j, color);
			//mlx_pixel_put(vars.mlx, win_ptr, i, j, 0x00FFFFFF);
		}
	}
	for (int i = 300, k = 0; i < 350; i++, k+=2)
	{
		for (int j = 150 + k; j < 250; j++)
		{
			double r = (double)(img_width - j) / (img_width - 1);
			double g = (double)(i) / (img_height - 1);
			double b = 1;
			color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) +((int)(255.999 * b));
			my_mlx_pixel_put(&image, i, j, color);
			//mlx_pixel_put(vars.mlx, win_ptr, i, j, 0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0);
	mlx_loop(vars.mlx);
	return (0);
}