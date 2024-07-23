#include "so_long.h"


key_hook(t_win_data *win_data)
{
	void *param;
	param = (void *)win_data;
	mlx_key_hook(win_data->win_ptr, &move_person, param);
}

// int move_person(int key, void *param)
int move_person(int key, void *param)
{
	t_win_data *win_data;
	win_data = (t_win_data *)param;


	if (key == KEY_ESC)
	{
		// destroy_tiles(win_data, tile_data);
		mlx_destroy_window(win_data->mlx_ptr, win_data->win_ptr);
		exit(0);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
			// move up
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
			// move down
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
			// move left
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
			// move right
	}
	
	return (0);
}

void	destroy_tiles(t_win_data *win_data, t_tile_data *tile_data)
{
	mlx_destroy_image (win_data->mlx_ptr, tile_data->rock);
	mlx_destroy_image (win_data->mlx_ptr, tile_data->grass);
	mlx_destroy_image (win_data->mlx_ptr, tile_data->person);
	mlx_destroy_image (win_data->mlx_ptr, tile_data->chest);
	mlx_destroy_image (win_data->mlx_ptr, tile_data->door);
}
// mouse_hook(int button,int x,int y,void *param);