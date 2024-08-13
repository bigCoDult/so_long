void	*set_tile_map0(t_total_data	*total_data)
{
	t_cordi	*cordi;

	total_data->tile_map = malloc(sizeof(t_tile_map));
	if (total_data->tile_map == NULL)
		return ;
	cordi = malloc(sizeof(t_cordi));
	if (cordi == NULL)
		return ;
	cordi->row = 0;
	while (cordi->row < total_data->char_map->row_size)
	{
		total_data->tile_map->map_cordi[cordi->row] = malloc(sizeof(void *) * total_data->char_map->col_size);
		if (total_data->tile_map->map_cordi[cordi->row] == NULL)
		{
			while (cordi->row >= 0)
				free(total_data->tile_map->map_cordi[cordi->row--]);
			free(total_data->tile_map);
			return (NULL);
		}

		cordi->col = 0;
		while (cordi->col < total_data->char_map->col_size)
		{
			if (total_data->char_map->map_cordi[cordi->row][cordi->col] == '1')
				total_data->tile_map->map_cordi[cordi->row][cordi->col] = total_data->tile_data->rock;
			else if (total_data->char_map->map_cordi[cordi->row][cordi->col] == '0')
				total_data->tile_map->map_cordi[cordi->row][cordi->col] = total_data->tile_data->grass;
			else if (total_data->char_map->map_cordi[cordi->row][cordi->col] == 'P')
				total_data->tile_map->map_cordi[cordi->row][cordi->col] = total_data->tile_data->person;
			else if (total_data->char_map->map_cordi[cordi->row][cordi->col] == 'C')
				total_data->tile_map->map_cordi[cordi->row][cordi->col] = total_data->tile_data->chest;
			else if (total_data->char_map->map_cordi[cordi->row][cordi->col] == 'E')
				total_data->tile_map->map_cordi[cordi->row][cordi->col] = total_data->tile_data->door;
			else
				return (NULL);
			cordi->col++;
		}
		cordi->row++;
	}
	return (NULL);
}










void	*set_char_map0(t_total_data *total_data)
{
	int row;
	int col;
	int index;
	total_data->char_map = malloc(sizeof(t_char_map) * 1);
	if (total_data->char_map == NULL)
		return (NULL);
	total_data->char_map->row_size = 0;
	total_data->char_map->col_size = 0;
	row = 0;
	col = 0;
	index = 0;
	while (total_data->map_str[index] != '\0')
	{
		if(map_str[index] == '\n')
			char_map->row_size++;
		index++;
	}
	char_map->col_size = index / char_map->row_size;
	char_map->map_cordi = malloc(sizeof(char *) * char_map->row_size);
	if (char_map->map_cordi == NULL)
		return (NULL);
	while (row < char_map->row_size)
	{
		char_map->map_cordi[row] = malloc(sizeof(char) * char_map->col_size);
		if (char_map->map_cordi[row] == NULL)
		{
			while (row-- >= 0)
				free(char_map->map_cordi[row]);
			free(char_map->map_cordi);
			return (NULL);
		}
		row++;
	}
	row = 0;
	index = 0;
	while (map_str[index] != '\0')
	{
		col = 0;
		while (map_str[index] != '\n')
		{
			char_map->map_cordi[row][col] = map_str[index];
			index++;
			col++;
		}
		index++;
		row++;
	}
	return (char_map);
}
