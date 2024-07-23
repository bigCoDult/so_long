#include "so_long.h"

int	main(int argc, char **argv)
{
	int fd;
	fd = open(argv[1], O_RDONLY);
	so_long(fd);
	return (0);
}

void so_long(int fd)
{
	t_total_data	*total_data;
	total_data = malloc(sizeof(t_total_data));
	if (total_data == NULL)
		return ;
	// total_data->win_data = malloc(sizeof(t_win_data));
	// if (total_data->win_data == NULL)
	// 	return ;
	init_win_data(total_data->win_data);
	deal_map(total_data);




	key_hook(total_data);
	mlx_loop(total_data->win_data->mlx_ptr);
	// mlx_loop_end(win_data->mlx_ptr);
}

int	main(void)
{
	so_long(0);
	return (0);
}