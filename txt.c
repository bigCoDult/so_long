
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
