#include "so_long.h"

key_hook(t_total_data *total_data)
{
	void *param;
	param = (void *)total_data;
	mlx_key_hook(total_data->win_data->win_ptr, &move_person, param);
}

int move_person(int key, void *param)
{
	t_total_data *total_data;
	total_data = (t_total_data *)param;
	
	if (key == KEY_ESC)
	{
		destroy_tiles(total_data);
		mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
		mlx_loop_end(total_data->win_data->mlx_ptr);
		exit(0);
		// exit이 뭐임
		// 프로세스 종료하는 거임
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

void	destroy_tiles(t_total_data *total_data)
{
	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->rock);
	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->grass);
	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->person);
	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->chest);
	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->door);
}
// mouse_hook(int button,int x,int y,void *param);