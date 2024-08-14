#include "so_long.h"

int	main(int argc, char **argv)
{
	int fd;
	// fd = open(argv[1], O_RDONLY);
	fd = open("map.ber", O_RDONLY);
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

	printf("%s\n", total_data->map_data->map_str);
	printf("row_size : %ld\n", total_data->map_data->row_size);
	printf("col_size : %ld\n", total_data->map_data->col_size);
	

	printf("is square : %d\n", is_square(total_data->map_data));
	printf("is wall : %d\n", is_wall(total_data->map_data));
	printf("is proper chars : %d\n", is_proper_chars(total_data->map_data));	
	// printf("is possible : %d\n", is_possible(total_data->map_data, get_cordi(total_data->map_data, PERSON)));
	
	init_win_data(total_data);
	deal_map(total_data);
	




	// key_hook(total_data);
	mlx_loop(total_data->win_data->mlx_ptr);
	mlx_loop_end(total_data->win_data->mlx_ptr);
}


void	init_win_data(t_total_data *total_data)
{
	total_data->win_data = malloc(sizeof(t_win_data));
	if (total_data->win_data == NULL)
		return ;
	total_data->win_data->title = "so_long";
	total_data->win_data->size_x = total_data->map_data->col_size * 20;
	total_data->win_data->size_y = total_data->map_data->row_size * 20;
	total_data->win_data->mlx_ptr = mlx_init();
	total_data->win_data->win_ptr = mlx_new_window(total_data->win_data->mlx_ptr, total_data->win_data->size_x, total_data->win_data->size_y, total_data->win_data->title);
	return ;
}

