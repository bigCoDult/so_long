#include "so_long.h"

void	*set_map_str(int fd, t_map_d *map_d)
{
	int	read_return;
	char buf[5];
	int index;
	map_d->map_str = malloc(sizeof(char) * 1);
	if (map_d->map_str == NULL)
		return (NULL);
	map_d->map_str[0] = '\0';
	while (1)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		map_d->map_str = join_s(map_d->map_str, buf);
		if (read_return < 5)
			break;
	}
	index = 0;
	map_d->row_size = 0;
	map_d->col_size = 0;
	while (1)
	{
		if (map_d->map_str[index] == '\n' || map_d->map_str[index] == '\0')
			map_d->row_size++;
		if (map_d->map_str[index] == '\0')
			break;
		index++;
	}
	map_d->col_size = index / map_d->row_size;
	return (NULL);
}

void	deal_map(t_tot	*tot)
{
	if (!validate_map(tot->map_d))
		return ;
	init_tiles(tot);
	set_vali_map(tot->map_d);
	set_c_map(tot->map_d);
	t_cor person;
	person = get_cor(tot->map_d, PERSON);
	if (!is_possible(tot->map_d, person))
		return ;
	return ;
}

void	*set_c_map(t_map_d *map_d)
{
	int r;
	int c;
	int index;
	
	r = 0;
	c = 0;
	index = 0;
	map_d->c_map = malloc(sizeof(char *) * map_d->row_size);
	if (map_d->c_map == NULL)
		return (NULL);
	while (r < map_d->row_size)
	{
		map_d->c_map[r] = malloc(sizeof(char) * map_d->col_size);
		if (map_d->c_map[r] == NULL)
		{
			while (r-- >= 0)
				free(map_d->c_map[r]);
			free(map_d->c_map);
			return (NULL);
		}
		r++;
	}
	r = 0;
	index = 0;
	while (r < map_d->row_size)
	{
		c = 0;
		while (c < map_d->col_size)
		{
			map_d->c_map[r][c] = map_d->map_str[index];
			index++;
			c++;
		}
		index++;
		r++;
	}
	return (NULL);
}

void	*set_vali_map(t_map_d *map_d)
{
	int r;
	int c;
	int index;
	r = 0;
	c = 0;
	index = 0;
	
	map_d->vali_map = malloc(sizeof(char *) * map_d->row_size);
	if (map_d->vali_map == NULL)
		return (NULL);
	while (r < map_d->row_size)
	{
		map_d->vali_map[r] = malloc(sizeof(char) * map_d->col_size);
		if (map_d->vali_map[r] == NULL)
		{
			while (r-- >= 0)
				free(map_d->vali_map[r]);
			free(map_d->vali_map);
			return (NULL);
		}
		r++;
	}
	r = 0;
	index = 0;
	while (r < map_d->row_size)
	{
		c = 0;
		while (c < map_d->col_size)
		{
			map_d->vali_map[r][c] = map_d->map_str[index];
			index++;
			c++;
		}
		index++;
		r++;
	}
	return (NULL);
}

void	*init_tiles(t_tot	*tot)
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

void draw_map(t_tot	*tot)
{
	int r;
	int c;
	int index;
	
	r = 0;
	c = 0;
	index = 0;
	while (r < tot->map_d->row_size)
	{
		c = 0;
		while (c < tot->map_d->col_size)
			if (tot->map_d->c_map[r][c] == WALL)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->rock, TILE_LEN * c++, TILE_LEN * r);		
			else if (tot->map_d->c_map[r][c] == EMPTY)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->grass, TILE_LEN * c++, TILE_LEN * r);		
			else if (tot->map_d->c_map[r][c] == PERSON)			
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->person, TILE_LEN * c++, TILE_LEN * r);		
			else if (tot->map_d->c_map[r][c] == COLLECT)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->chest, TILE_LEN * c++, TILE_LEN * r);		
			else if (tot->map_d->c_map[r][c] == EXIT)
				mlx_put_image_to_window (tot->win_data->mlx_ptr, tot->win_data->win_ptr, tot->tile_data->door, TILE_LEN * c++, TILE_LEN * r);		
		r++;
	}
}
