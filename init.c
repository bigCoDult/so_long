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
	int index;
	index = 0;
	map_data->row_size = 0;
	map_data->col_size = 0;
	while (1)
	{
		if (map_data->map_str[index] == '\n' || map_data->map_str[index] == '\0')
			map_data->row_size++;
		if (map_data->map_str[index] == '\0')
			break;
		index++;
	}
	map_data->col_size = index / map_data->row_size;
	return (NULL);
}

void	deal_map(t_total_data	*total_data)
{
	if (!validate_map(total_data->map_data))
		return ;
	int veli = 0;
	init_tiles(total_data);
	set_vali_map(total_data->map_data);
	set_char_map(total_data->map_data);
	
	printf("is possible : %d\n", is_possible(total_data->map_data, get_cordi(total_data->map_data, PERSON)));
	printf("is square : %d\n", is_square(total_data->map_data));
	printf("is wall : %d\n", is_wall(total_data->map_data));
	printf("is proper chars : %d\n", is_proper_chars(total_data->map_data));	
	draw_map(total_data);
	return ;
}

void	*set_char_map(t_map_data *map_data)
{
	int row;
	int col;
	int index;
	
	row = 0;
	col = 0;
	index = 0;
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

void	*set_vali_map(t_map_data *map_data)
{
	int row;
	int col;
	int index;
	row = 0;
	col = 0;
	index = 0;
	
	map_data->vali_map = malloc(sizeof(char *) * map_data->row_size);
	if (map_data->vali_map == NULL)
		return (NULL);
	while (row < map_data->row_size)
	{
		map_data->vali_map[row] = malloc(sizeof(char) * map_data->col_size);
		if (map_data->vali_map[row] == NULL)
		{
			while (row-- >= 0)
				free(map_data->vali_map[row]);
			free(map_data->vali_map);
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
			// map_data->vali_map[row][col] = 0;
			map_data->vali_map[row][col] = map_data->map_str[index];
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
	total_data->tile_data->rock = open_xpm(total_data->win_data, NULL, "rock");
	total_data->tile_data->grass = open_xpm(total_data->win_data, NULL, "grass");
	total_data->tile_data->door = open_xpm(total_data->win_data, NULL, "door");
	total_data->tile_data->chest = open_xpm(total_data->win_data, NULL, "chest");
	total_data->tile_data->person = open_xpm(total_data->win_data, NULL, "person");
	// return (널말고 뭘 반환?);
	return (NULL);
}

void draw_map(t_total_data	*total_data)
{
	int row;
	int col;
	int index;
	
	row = 0;
	col = 0;
	index = 0;
	while (row < total_data->map_data->row_size)
	{
		col = 0;
		while (col < total_data->map_data->col_size)
			if (total_data->map_data->char_map[row][col] == WALL)
				mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->tile_data->rock, TILE_LEN * col++, TILE_LEN * row);		
			else if (total_data->map_data->char_map[row][col] == EMPTY)
				mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->tile_data->grass, TILE_LEN * col++, TILE_LEN * row);		
			else if (total_data->map_data->char_map[row][col] == PERSON)			
				mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->tile_data->person, TILE_LEN * col++, TILE_LEN * row);		
			else if (total_data->map_data->char_map[row][col] == COLLECT)
				mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->tile_data->chest, TILE_LEN * col++, TILE_LEN * row);		
			else if (total_data->map_data->char_map[row][col] == EXIT)
				mlx_put_image_to_window (total_data->win_data->mlx_ptr, total_data->win_data->win_ptr, total_data->tile_data->door, TILE_LEN * col++, TILE_LEN * row);		
		row++;
	}
}
