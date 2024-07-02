#include "so_long.h"

void so_long(int fd)
{
	void *mlx_ptr;
	int size_x = 500;
	int size_y = 500;
	char *title = "hi";
	mlx_init();
	mlx_new_window(mlx_ptr, size_x, size_y, title);

}

int	main(void)
{
	so_long(0);
	return (0);
}