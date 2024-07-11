#include "so_long.h"

void so_long(int fd)
{
	t_win_data	*win_data;
	win_data = malloc(sizeof(t_win_data));
	if (win_data == NULL)
		return ;
	init_win_data(win_data);
	init_tile(win_data);
	// set_map(win_data, init_tile(win_data));
	// int tile = 0;

}

int	main(void)
{
	so_long(0);
	return (0);
}