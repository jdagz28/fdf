#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#define GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define MLX_ERROR 1
#define ESC_KEY 53

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int 	is_mouse_inside;
}				t_win;


typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void	render_circle(t_data data, int center_x, int center_y, int radius, int color)
{
	int x, y;

	for (x = center_x - radius; x <= center_x + radius; x++)
	{
		for (y = center_y - radius; y <= center_y + radius; y++)
		{
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius)
				my_mlx_pixel_put(&data, x, y, color);
		}
	}
}

int render_rect (t_data data, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(&data, j++, i, rect.color);
		i++;
	}
	return (0);
}

void	render_background(t_data data, int color)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&data, j++, i, color);
		}
		i++;
	}
}
int render(t_data data)
{
	render_background(data, WHITE_PIXEL);
	// render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	// render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	render_circle(data, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 100, RED_PIXEL);
	return (0);
}

int close_window(t_win *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	return (0);
}

int key_press(int keycode, t_win *mlx)
{
    (void) ml
	printf("Key pressed: %d\n", keycode);
    return (0);
}
int mouse_move(int x, int y, t_win *mlx)
{
    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
    {
        if (!mlx->is_mouse_inside)
        {
            mlx->is_mouse_inside = 1;
            printf("Hello!\n");
        }
    }
    else
    {
        if (mlx->is_mouse_inside)
        {
            mlx->is_mouse_inside = 0;
            printf("Bye!\n");
        }
    }
    return (0);
}


int main(void)
{
    t_data    	img;
	t_win		mlx;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	mlx.is_mouse_inside = 0;
	img.img = mlx_new_image(mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	render(img);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_hook(mlx.mlx_win, 6, 1L << 6, mouse_move, &mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	while (1)
		;
	free(mlx.mlx_win);
	free(mlx.mlx);
}

//WITH SHADE
// #include <stdlib.h>
// #include <math.h>
// #include <mlx.h>

// #define WINDOW_WIDTH 800
// #define WINDOW_HEIGHT 600
// #define MLX_ERROR 1
// #define ESC_KEY 53

// typedef struct s_data {
// 	void *mlx;
// 	void *mlx_win;
// 	void *img;
// 	char *addr;
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;
// } t_data;

// typedef struct s_point {
// 	int x;
// 	int y;
// } t_point;

// typedef struct s_color {
// 	int r;
// 	int g;
// 	int b;
// } t_color;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// t_color interpolate_color(t_color color1, t_color color2, float t)
// {
// 	t_color result;
// 	result.r = (int)(color1.r * (1 - t) + color2.r * t);
// 	result.g = (int)(color1.g * (1 - t) + color2.g * t);
// 	result.b = (int)(color1.b * (1 - t) + color2.b * t);
// 	return result;
// }

// t_color get_shaded_color(t_color base_color, float shade_factor)
// {
// 	t_color white = {255, 255, 255};
// 	return interpolate_color(base_color, white, shade_factor);
// }

// void render_circle(t_data *data, t_point center, int radius, t_color base_color)
// {
// 	int x, y;

// 	for (x = center.x - radius; x <= center.x + radius; x++)
// 	{
// 		for (y = center.y - radius; y <= center.y + radius; y++)
// 		{
// 			if ((x - center.x) * (x - center.x) + (y - center.y) * (y - center.y) <= radius * radius)
// 			{
// 				float distance = sqrtf((x - center.x) * (x - center.x) + (y - center.y) * (y - center.y));
// 				float shade_factor = distance / radius;
// 				t_color shaded_color = get_shaded_color(base_color, shade_factor);
// 				int color = (shaded_color.r << 16) | (shaded_color.g << 8) | shaded_color.b;
// 				my_mlx_pixel_put(data, x, y, color);
// 			}
// 		}
// 	}
// }

// int close_window(t_data *data)
// {
// 	mlx_destroy_window(data->mlx, data->mlx_win);
// 	exit(0);
// }

// int key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC_KEY)
// 		close_window(data);
// 	return (0);
// }

// int main(void)
// {
// 	t_data data;

// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Shaded Circle Example");
// 	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

// 	t_point center = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
// 	int radius = 200;
// 	t_color base_color = {255, 0, 0}; // Red color

// 	render_circle(&data, center, radius, base_color);

// 	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
// 	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
// 	mlx_hook(data.mlx_win, 17, 1L << 0, close_window, &data);
// 	mlx_loop(data.mlx);

// 	return (0);
// }
