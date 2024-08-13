#include "so_long.h"

void	*set_map_str(int fd, t_map_data *map_data)
{
	int	read_return;
	char buf[5];
	map_data->map_str = malloc(sizeof(char) * 1);
	if (map_data->map_str == NULL)
		return (NULL);
	map_data->map_str[0] = '\0';
	while (1)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		map_data->map_str = join_s(map_data->map_str, buf);
		if (read_return < 5)
			break;
	}
	return (NULL);
}

void	deal_map(t_total_data	*total_data)
{
	if (!validate_map(total_data->map_data))
		return ;
	set_char_map(total_data->map_data);
	init_tiles(total_data);
	// set_tile_map(total_data);
	// draw_tile_map(total_data);
	return ;
}

void	*set_char_map(t_map_data *map_data)
{
	int row;
	int col;
	int index;
	map_data->row_size = 0;
	map_data->col_size = 0;
	row = 0;
	col = 0;
	index = 0;
	while (1)
	{
		if (map_data->map_str[index] == '\n' || map_data->map_str[index] == '\0')
			map_data->row_size++;
		if (map_data->map_str[index] == '\0')
			break;
		index++;
	}
	map_data->col_size = index / map_data->row_size;
	printf("row_size : %ld\n", map_data->row_size);
	printf("col_size : %ld\n", map_data->col_size);
	map_data->char_map = malloc(sizeof(char *) * map_data->row_size);
	if (map_data->char_map == NULL)
		return (NULL);
	while (row < map_data->row_size)
	{
		map_data->char_map[row] = malloc(sizeof(char) * map_data->col_size);
		if (map_data->char_map[row] == NULL)
		{
			while (row-- >= 0)
				free(map_data->char_map[row]);
			free(map_data->char_map);
			return (NULL);
		}
		row++;
	}
	row = 0;
	index = 0;
	while (row < map_data->row_size)
	{
		col = 0;
		while (col < map_data->col_size)
		{
			map_data->char_map[row][col] = map_data->map_str[index];
			index++;
			col++;
		}
		index++;
		row++;
	}
	return (NULL);
}


void	*init_tiles(t_total_data	*total_data)
{
	total_data->tile_data = malloc(sizeof(t_tile_data));
	if (total_data->tile_data == NULL)
		return (NULL);
	// total_data->tile_data->tile_location = set_tile_location(total_data);
	total_data->tile_data->rock = open_xpm(total_data->win_data, NULL, "rock");
	total_data->tile_data->grass = open_xpm(total_data->win_data, NULL, "grass");
	total_data->tile_data->door = open_xpm(total_data->win_data, NULL, "door");
	total_data->tile_data->chest = open_xpm(total_data->win_data, NULL, "chest");
	total_data->tile_data->person = open_xpm(total_data->win_data, NULL, "person");
	// return (널말고 뭘 반환?);
	return (NULL);
}

// void	*set_tile_location(t_total_data	*total_data)
// {
// 	int row;
// 	int col;
// 	// tile_location[row][col][가로픽셀 위치, 세로픽셀 위치]
// 	total_data->tile_data->tile_location = malloc(sizeof(int **) * total_data->map_data->row_size);
// 	if (total_data->tile_data->tile_location == NULL)
// 		return (NULL);
// 	row = 0;
// 	while (row < total_data->map_data->row_size)
// 	{
// 		total_data->tile_data->tile_location[row] = malloc(sizeof(int *) * total_data->map_data->col_size);
// 		if (total_data->tile_data->tile_location[row] == NULL)
// 		{
// 			while (row >= 0)
// 			{
// 				col = 0;
// 				while (col < total_data->map_data->col_size)
// 					free(total_data->tile_data->tile_location[row][col++]);
// 				free(total_data->tile_data->tile_location[row]);
// 				row--;
// 			}
// 			free(total_data->tile_data->tile_location);
// 			return (NULL);
// 		}
// 		col = 0;
// 		while (col < total_data->map_data->col_size)
// 		{
// 			total_data->tile_data->tile_location[row][col] = malloc(sizeof(int) * 2);
// 			if (total_data->tile_data->tile_location[row][col] == NULL)
// 			{
// 				while (--row >= 0)
// 				{
// 					col = 0;
// 					while (col < total_data->map_data->col_size)
// 					{
// 						free(total_data->tile_data->tile_location[row][col]);
// 						col++;
// 					}
// 					free(total_data->tile_data->tile_location[row]);
// 				}
// 				free(total_data->tile_data->tile_location);
// 				return (NULL);
// 			}
// 			total_data->tile_data->tile_location[row][col][0] = TILE_LEN * row;
// 			total_data->tile_data->tile_location[row][col][1] = TILE_LEN * col;
// 			col++;
// 		}
// 		row++;
// 	}
// 	// return (total_data);
// 	return (NULL);
// }

void	*set_tile_map(t_total_data *total_data)
{
	int row;
	int col;
	int index;
	
	row = 0;
	col = 0;
	index = 0;
	
	while (row < total_data->map_data->row_size)
	{
		total_data->map_data->tile_map[row] = malloc(sizeof(void **) * total_data->map_data->row_size);
		if (total_data->map_data->tile_map[row] == NULL)
		{
			while (row-- >= 0)
				free(total_data->map_data->tile_map[row]);
			free(total_data->map_data->tile_map);
			return (NULL);
		}
		while (col < total_data->map_data->col_size)
		{
			if (total_data->map_data->char_map[row][col] == WALL)
				total_data->map_data->tile_map[row][col] = total_data->tile_data->rock;
			else if (total_data->map_data->char_map[row][col] == EMPTY)
				total_data->map_data->tile_map[row][col] = total_data->tile_data->grass;
			else if (total_data->map_data->char_map[row][col] == PERSON)
				total_data->map_data->tile_map[row][col] = total_data->tile_data->person;
			else if (total_data->map_data->char_map[row][col] == COLLECT)
				total_data->map_data->tile_map[row][col] = total_data->tile_data->chest;
			else if (total_data->map_data->char_map[row][col] == EXIT)
				total_data->map_data->tile_map[row][col] = total_data->tile_data->door;
			total_data->map_data->col_size++;
		}
		total_data->map_data->row_size++;
	}
	return (NULL);
}

void draw_tile_map(t_total_data	*total_data)
{
	int row;
	int col;
	int index;
	row = 0;
	col = 0;
	index = 0;
	
	while (row <= total_data->map_data->row_size)
	{
		col = 0;
		while (col <= total_data->map_data->col_size)
			// mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->map_data->tile_map[row][col], total_data->tile_data->tile_location[row][col][0], total_data->tile_data->tile_location[row][col++][1]);
			mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->map_data->tile_map[row][col], TILE_LEN * row, TILE_LEN * col++);	
		row++;
	}
}

