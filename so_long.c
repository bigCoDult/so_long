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
	t_tot	*tot;
	tot = malloc(sizeof(t_tot));
	if (tot == NULL)
		return ;
	tot->win_data = malloc(sizeof(t_win_data));
	if (tot->win_data == NULL)
		return ;
	tot->map_d = malloc(sizeof(t_map_d));
	if (tot->map_d == NULL)
		return ;

	tot->map_d->vali_map = set_map_str(fd, tot->map_d);
	
	init_win_data(tot);
	deal_map(tot);
	key_hook(tot);
	//key hook 안에 mlx_loop_end가 있어야 함
	mlx_loop(tot->win_data->mlx_ptr);
	// mlx_hook(tot->win_data->win_ptr, 17, 0, end_game, tot); 
		// 게임 종료
		// 안되는디?
	end_game(tot);
		//이부분에 end game 하면 exit(0) 필요 없음
}


void	init_win_data(t_tot *tot)
{
	tot->win_data->title = "so_long";
	tot->win_data->size_x = tot->map_d->col_size * 20;
	tot->win_data->size_y = tot->map_d->row_size * 20;
	tot->win_data->mlx_ptr = mlx_init();
	tot->win_data->win_ptr = mlx_new_window(tot->win_data->mlx_ptr, tot->win_data->size_x, tot->win_data->size_y, tot->win_data->title);
	return ;
}

t_cor	get_cor(t_map_d *map_d, char c)
{
	t_cor	person;
	person = (t_cor){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < map_d->row_size)
	{
		person.c = 0;
		while (person.c < map_d->col_size)
		{
			if (map_d->c_map[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return (t_cor){-1, -1};
}

