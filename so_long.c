#include "./minilibx-linux/mlx.h"

void so_long(int fd)
{
	void *mlx_ptr;
	void	*win_ptr;
	int size_x = 500;
	int size_y = 500;
	char *title = "hi";
	int tile_len = 20;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, title);
	int map[10][10][2];
	int row;
	int col;
	row = 0;
	col = 0;
	while (col <= 9)
	{
		row = 0;
		while (row <= 9)
		{
			map[row][col][0] = row * tile_len;
			map[row][col][1] = col * tile_len;
			row++;
		}
		col++;
	}

	void *door = mlx_xpm_file_to_image(mlx_ptr, "./tile/door.xpm", &tile_len, &tile_len);
	void *chest = mlx_xpm_file_to_image(mlx_ptr, "./tile/chest.xpm", &tile_len, &tile_len);
	void *grass = mlx_xpm_file_to_image(mlx_ptr, "./tile/grass.xpm", &tile_len, &tile_len);
	void *rock = mlx_xpm_file_to_image(mlx_ptr, "./tile/rock.xpm", &tile_len, &tile_len);
	int is_error;
	is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, door, map[0][0][0], map[0][0][1]);
	is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, chest, map[1][0][0], map[1][0][1]);
	is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, grass, map[0][2][0], map[0][2][1]);
	is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, rock, map[2][1][0], map[2][1][1]);

	mlx_loop(mlx_ptr);
}

int	main(void)
{
	so_long(0);
	return (0);
}