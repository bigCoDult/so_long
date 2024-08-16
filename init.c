#include "so_long.h"

void	*set_map_str(int fd, t_map_data *map_data)
{
	int	read_return;
	char buf[5];
	int index;
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

void	deal_map(t_total_data	*tot)
{
	if (!validate_map(tot->map_data))
		return ;
	init_tiles(tot);
	set_vali_map(tot->map_data);
	set_char_map(tot->map_data);
	t_cordi person;
	person = get_cordi(tot->map_data, PERSON);
	if (!is_possible(tot->map_data, person))
		return ;
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
			map_data->vali_map[row][col] = map_data->map_str[index];
			index++;
			col++;
		}
		index++;
		row++;
	}
	return (NULL);
}

void	*init_tiles(t_total_data	*tot)
{
	tot->tile_data = malloc(sizeof(t_tile_data));
	if (tot->tile_data == NULL)
		return (NULL);
	tot->tile_data->rock = open_xpm(tot->win_data, NULL, "rock");
	tot->tile_data->grass = open_xpm(tot->win_data, NULL, "grass");
	tot->tile_data->person = open_xpm(tot->win_data, NULL, "person");
	tot->tile_data->chest = open_xpm(tot->win_data, NULL, "chest");
	tot->tile_data->door = open_xpm(tot->win_data, NULL, "door");
	// return (널말고 뭘 반환?);
	return (NULL);
}

void draw_map(t_total_data	*tot)
{
	int row;
	int col;
	int index;
	
	row = 0;
	col = 0;
	index = 0;
	while (row < tot->map_data->row_size)
	{
		col = 0;
		while (col < tot->map_data->col_size)
			if (tot->map_data->char_map[row][col] == WALL)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->rock, TILE_LEN * col++, TILE_LEN * row);		
			else if (tot->map_data->char_map[row][col] == EMPTY)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->grass, TILE_LEN * col++, TILE_LEN * row);		
			else if (tot->map_data->char_map[row][col] == PERSON)			
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->person, TILE_LEN * col++, TILE_LEN * row);		
			else if (tot->map_data->char_map[row][col] == COLLECT)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->chest, TILE_LEN * col++, TILE_LEN * row);		
			else if (tot->map_data->char_map[row][col] == EXIT)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->door, TILE_LEN * col++, TILE_LEN * row);		
		row++;
	}
}
