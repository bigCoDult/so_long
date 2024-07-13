#include "so_long.h"

void so_long(int fd)
{
	t_win_data	*win_data;
	win_data = malloc(sizeof(t_win_data));
	if (win_data == NULL)
		return ;
	init_win_data(win_data);
	deal_map(win_data);
	mlx_loop(win_data->mlx_ptr);


}

int	main(void)
{
	so_long(0);
	return (0);
}