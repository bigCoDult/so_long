#include "so_long.h"

void	key_hook(t_total_data *total_data)
{
	void *param;
	param = (void *)total_data;
	draw_map(total_data);
	is_proper_chars(total_data->map_data);

	mlx_key_hook(total_data->win_data->win_ptr, &move_person, param);
	return ;
}

int move_person(int key, void *param)
{
	t_total_data *total_data;
	total_data = (t_total_data *)param;
	t_cordi *person;
	person = malloc(sizeof(t_cordi));
	if (person == NULL)
		return (0);
	person = get_cordi(total_data->map_data, 'P');
	
	if (key == KEY_ESC)
	{
		// destroy_tiles(total_data);
		mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
		mlx_loop_end(total_data->win_data->mlx_ptr);
		exit(0);
		// exit이 뭐임
		// 프로세스 종료하는 거임
	}
	else if (key == KEY_W || key == KEY_UP)
	{
			// printf("move up\n");
			if (total_data->map_data->vali_map[person->row - 1][person->col] == WALL)
				return (0);
			if (total_data->map_data->vali_map[person->row - 1][person->col] == COLLECT)
				total_data->map_data->count_collect--;
			if (total_data->map_data->vali_map[person->row - 1][person->col] == EXIT && total_data->map_data->count_collect != 0)
				return (0);
			if (total_data->map_data->vali_map[person->row - 1][person->col] == EXIT && total_data->map_data->count_collect == 0)
			{
				mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
				mlx_loop_end(total_data->win_data->mlx_ptr);
				exit(0);
			}
			total_data->map_data->char_map[person->row][person->col] = '0';
			total_data->map_data->char_map[person->row - 1][person->col] = 'P';
			printf("count_collect : %d\n", total_data->map_data->count_collect);
			draw_map(total_data);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
			// printf("move down\n");
			if (total_data->map_data->vali_map[person->row + 1][person->col] == '1')
				return (0);
			if (total_data->map_data->vali_map[person->row + 1][person->col] == COLLECT)
				total_data->map_data->count_collect--;
			if (total_data->map_data->vali_map[person->row + 1][person->col] == EXIT && total_data->map_data->count_collect != 0)
				return (0);
			if (total_data->map_data->vali_map[person->row + 1][person->col] == EXIT && total_data->map_data->count_collect == 0)
			{
				mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
				mlx_loop_end(total_data->win_data->mlx_ptr);
				exit(0);
			}			
			total_data->map_data->char_map[person->row][person->col] = '0';
			total_data->map_data->char_map[person->row + 1][person->col] = 'P';
			printf("count_collect : %d\n", total_data->map_data->count_collect);
			draw_map(total_data);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
			// printf("move left\n");
			if (total_data->map_data->vali_map[person->row][person->col - 1] == '1')
				return (0);
			if (total_data->map_data->vali_map[person->row][person->col - 1] == COLLECT)
				total_data->map_data->count_collect--;
			if (total_data->map_data->vali_map[person->row][person->col - 1] == EXIT && total_data->map_data->count_collect != 0)
				return (0);
			if (total_data->map_data->vali_map[person->row][person->col - 1] == EXIT && total_data->map_data->count_collect == 0)
			{
				mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
				mlx_loop_end(total_data->win_data->mlx_ptr);
				exit(0);
			}			
			total_data->map_data->char_map[person->row][person->col] = '0';
			total_data->map_data->char_map[person->row][person->col - 1] = 'P';
			printf("count_collect : %d\n", total_data->map_data->count_collect);
			draw_map(total_data);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
			// printf("move right\n");
			if (total_data->map_data->vali_map[person->row][person->col + 1] == '1')
				return (0);
			if (total_data->map_data->vali_map[person->row][person->col + 1] == COLLECT)
				total_data->map_data->count_collect--;
			if (total_data->map_data->vali_map[person->row][person->col + 1] == EXIT && total_data->map_data->count_collect != 0)
				return (0);
			if (total_data->map_data->vali_map[person->row][person->col + 1] == EXIT && total_data->map_data->count_collect == 0)
			{
				mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
				mlx_loop_end(total_data->win_data->mlx_ptr);
				exit(0);
			}			

			total_data->map_data->char_map[person->row][person->col] = '0';
			total_data->map_data->char_map[person->row][person->col + 1] = 'P';
			printf("count_collect : %d\n", total_data->map_data->count_collect);
			draw_map(total_data);
	}
	
	return (0);
}

// void	destroy_tiles(t_total_data *total_data)
// {
// 	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->rock);
// 	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->grass);
// 	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->person);
// 	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->chest);
// 	mlx_destroy_image (total_data->win_data->mlx_ptr, total_data->tile_data->door);
// }
// mouse_hook(int button,int x,int y,void *param);