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
	int step;
	step = 0;
	t_total_data *total_data;
	total_data = (t_total_data *)param;
	t_cordi person;
	person = get_cordi(total_data->map_data, 'P');
	if (key == KEY_ESC)
	{
		// end_game(total_data);
		mlx_loop_end(total_data->win_data->mlx_ptr);
		return (0);
	}
	else if (key == KEY_W || key == KEY_UP)
	{
		if (total_data->map_data->char_map[person.row - 1][person.col] == WALL)
			return (0);
		if (total_data->map_data->char_map[person.row - 1][person.col] == COLLECT)
			total_data->map_data->count_collect--;
		if (total_data->map_data->char_map[person.row - 1][person.col] == EXIT && total_data->map_data->count_collect != 0)
			return (0);
		if (total_data->map_data->char_map[person.row - 1][person.col] == EXIT && total_data->map_data->count_collect == 0)
		{
			mlx_loop_end(total_data->win_data->mlx_ptr);
				// end_game(total_data);
			return (0);
		}
		total_data->map_data->char_map[person.row][person.col] = '0';
		total_data->map_data->char_map[person.row - 1][person.col] = 'P';
		// printf("count_collect : %d\n", total_data->map_data->count_collect);
		// printf("you step : %d", ++step);
		draw_map(total_data);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		if (total_data->map_data->char_map[person.row + 1][person.col] == WALL)
			return (0);
		if (total_data->map_data->char_map[person.row + 1][person.col] == COLLECT)
			total_data->map_data->count_collect--;
		if (total_data->map_data->char_map[person.row + 1][person.col] == EXIT && total_data->map_data->count_collect != 0)
			return (0);
		if (total_data->map_data->char_map[person.row + 1][person.col] == EXIT && total_data->map_data->count_collect == 0)
		{
			end_game(total_data);
			return (0);
		}
		total_data->map_data->char_map[person.row][person.col] = '0';
		total_data->map_data->char_map[person.row + 1][person.col] = 'P';
		// printf("count_collect : %d\n", total_data->map_data->count_collect);
		// printf("you step : %d", ++step);
		draw_map(total_data);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		if (total_data->map_data->char_map[person.row][person.col - 1] == WALL)
			return (0);
		if (total_data->map_data->char_map[person.row][person.col - 1] == COLLECT)
			total_data->map_data->count_collect--;
		if (total_data->map_data->char_map[person.row][person.col - 1] == EXIT && total_data->map_data->count_collect != 0)
			return (0);
		if (total_data->map_data->char_map[person.row][person.col - 1] == EXIT && total_data->map_data->count_collect == 0)
		{
			end_game(total_data);
			return (0);
		}
		total_data->map_data->char_map[person.row][person.col] = '0';
		total_data->map_data->char_map[person.row][person.col - 1] = 'P';
		// printf("count_collect : %d\n", total_data->map_data->count_collect);
		// printf("you step : %d", ++step);
		draw_map(total_data);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		if (total_data->map_data->char_map[person.row][person.col + 1] == WALL)
			return (0);
		if (total_data->map_data->char_map[person.row][person.col + 1] == COLLECT)
			total_data->map_data->count_collect--;
		if (total_data->map_data->char_map[person.row][person.col + 1] == EXIT && total_data->map_data->count_collect != 0)
			return (0);
		if (total_data->map_data->char_map[person.row][person.col + 1] == EXIT && total_data->map_data->count_collect == 0)
		{
			end_game(total_data);
			return (0);
		}
		total_data->map_data->char_map[person.row][person.col] = '0';
		total_data->map_data->char_map[person.row][person.col + 1] = 'P';
		// printf("count_collect : %d\n", total_data->map_data->count_collect);
		// printf("you step : %d", ++step);
		draw_map(total_data);
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

// int	move_direction(t_map_data map_data, t_cordi person, char *direction)
// {
// 	if (direction == "up")
// 	{
// 		if (map_data->char_map[person.row - 1][person.col] == WALL)
// 			return (0);
// 		if (total_data->map_data->char_map[person.row - 1][person.col] == COLLECT)
// 			total_data->map_data->count_collect--;
// 		if (total_data->map_data->char_map[person.row - 1][person.col] == EXIT && total_data->map_data->count_collect != 0)
// 			return (0);
// 		if (total_data->map_data->char_map[person.row - 1][person.col] == EXIT && total_data->map_data->count_collect == 0)
// 		{
// 			mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
// 			mlx_loop_end(total_data->win_data->mlx_ptr);
// 			exit(0);
// 		}
// 		total_data->map_data->char_map[person.row][person.col] = '0';
// 		total_data->map_data->char_map[person.row - 1][person.col] = 'P';
// 		printf("count_collect : %d\n", total_data->map_data->count_collect);
// 		draw_map(total_data);
// 	}
// }

int end_game(t_total_data *total_data)
{
	int a = total_data->map_data->row_size;
	int b = a;
	
	// mlx_loop_end(total_data->win_data->mlx_ptr);
		// 아무 변화 없음
		// 에러만 늘어남
	// mlx_clear_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
		// 아무 변화 없음
	destroy_tiles(total_data);
	mlx_destroy_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
	mlx_destroy_display(total_data->win_data->mlx_ptr);
	
	while (a--)
		free(total_data->map_data->char_map[a]);
	free(total_data->map_data->char_map);
	while (b--)
		free(total_data->map_data->vali_map[b]);
	free(total_data->map_data->vali_map);	
	
	free(total_data->map_data->map_str);
	free(total_data->map_data);
	
	free(total_data->tile_data);
	
	free(total_data->win_data->mlx_ptr);
		// still reachable이 28로 확 줄어듬
		// 근데 이걸 쓰면 에러가 8개 늘어남
	free(total_data->win_data);
	free(total_data);
	return (0);	
	// exit(0);
}

// 불필요한 free
int no_game(t_total_data *total_data)		
{
	free(total_data->win_data->win_ptr);
		// 이거 더블 프리임
	free(total_data->win_data->mlx_ptr);
		// still reachable이 28로 확 줄어듬
		// 근데 이걸 쓰면 에러가 8개 늘어남
	mlx_clear_window(total_data->win_data->mlx_ptr, total_data->win_data->win_ptr);
		// ERROR SUMMARY: 17 errors from 14 contexts
		// ERROR SUMMARY: 36 errors from 30 contexts
		// 에러 늘어남 안써야할거 같음
	free(total_data->win_data->title);
		// 줄어드는건 없고 에러만 늘어남
	free(total_data->win_data);
		// 줄어드는건 없고 에러만 늘어남
	free(total_data->tile_data);
		// 줄어드는건 없고 에러만 한개 늘어남
	free(total_data->tile_data->rock);
		// 이거 더블 프리임
}