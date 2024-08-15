#include "so_long.h"

int	main(int argc, char **argv)
{
	int fd;
	// fd = open(argv[1], O_RDONLY);
	fd = open("map.ber", O_RDONLY);
	//개체 2개 생성
	// 점찍는 함수 호출, set_drawing_dot
	// 그림 그리는 함수 호출, draw_graphic
	// mlx_loop 호출, excute_loop
	// key_hook 호출, 이 안에서 mlx_loop_end 호출
	//free 기타잡것함수 호출

	so_long(fd);
	close(fd);
	return (0);
}

void so_long(int fd)
{
	t_total_data	*total_data;
	total_data = malloc(sizeof(t_total_data));
	if (total_data == NULL)
		return ;
	total_data->win_data = malloc(sizeof(t_win_data));
	if (total_data->win_data == NULL)
		return ;
	total_data->map_data = malloc(sizeof(t_map_data));
	if (total_data->map_data == NULL)
		return ;

	total_data->map_data->vali_map = set_map_str(fd, total_data->map_data);
	
	init_win_data(total_data);
	deal_map(total_data);
	key_hook(total_data);
	//key hook 안에 mlx_loop_end가 있어야 함
	mlx_loop(total_data->win_data->mlx_ptr);
	//이부분에 end game 하면 exit 필요 없음
	end_game(total_data);
}


void	init_win_data(t_total_data *total_data)
{
	total_data->win_data->title = "so_long";
	total_data->win_data->size_x = total_data->map_data->col_size * 20;
	total_data->win_data->size_y = total_data->map_data->row_size * 20;
	total_data->win_data->mlx_ptr = mlx_init();
	total_data->win_data->win_ptr = mlx_new_window(total_data->win_data->mlx_ptr, total_data->win_data->size_x, total_data->win_data->size_y, total_data->win_data->title);
	return ;
}

