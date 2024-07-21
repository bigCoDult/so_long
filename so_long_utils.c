#include "so_long.h"

char	*template_literal(char *line, char *word, int location)
{
	char		*str;
	size_t	str_i;
	size_t	line_i;
	size_t	word_i;

	str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(word) + 1));
	if (str == NULL)
		return (NULL);
	str_i = 0;
	line_i = 0;
	word_i = 0;
	if (ft_strlen(line) < location)
		return ("wrong location");
	while (line_i < location)
	{
		str[str_i] = line[line_i];
		str_i++;
		line_i++;
	}
	while (word_i < ft_strlen(word))
	{
		str[str_i] = word[word_i];
		str_i++;
		word_i++;
	}
	while (line[line_i] != '\0')
	{
		str[str_i] = line[line_i];
		str_i++;
		line_i++;
	}
	str[str_i] = '\0';
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length] != '\0')
		length++;
	return (length);
}

char	*join_s(char *st_s, char *buf)
{
	char	*new_line;

	new_line = join_s_till_c(st_s, buf, '\0');
	if (new_line == NULL)
	{
		return (NULL);
	}
	free(st_s);
	st_s = new_line;
	return (st_s);
}

char	*join_s_till_c(char *s1, char *s2, char c)
{
	char	*out_s;
	size_t	i_in_s1;
	size_t	i_in_s2;
	size_t	i_out;

	i_in_s1 = 0;
	i_in_s2 = 0;
	i_out = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	out_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (out_s == NULL)
		return (NULL);
	while (s1 && s1[i_in_s1] != c)
		out_s[i_out++] = s1[i_in_s1++];
	while (s2 && s2[i_in_s2] != c)
		out_s[i_out++] = s2[i_in_s2++];
	out_s[i_out] = '\0';
	return (out_s);
}







void	init_win_data(t_win_data*win_data)
{
	win_data->title = "so_long";
	win_data->size_x = 500;
	win_data->size_y = 500;
	win_data->mlx_ptr = mlx_init();
	win_data->win_ptr = mlx_new_window(win_data->mlx_ptr, win_data->size_x, win_data->size_y, win_data->title);
	return ;
}





void	deal_map(t_win_data *win_data)
{
	t_tile_data	*tile_data;
	t_char_map *char_map;
	tile_data = malloc(sizeof(t_tile_data));
	if (tile_data == NULL)
		return ;
	char_map = malloc(sizeof(t_char_map));
	if (char_map == NULL)
		return ;
	char_map = validate_map();
	tile_data = init_tiles(win_data);
	draw_tile_map(win_data, tile_data, set_tile_map(win_data, tile_data, char_map));
	return ;
}

t_tile_map	*set_tile_map(t_win_data *win_data, t_tile_data *tile_data, t_char_map *char_map)
{
	t_tile_map *tile_map;
	t_cordi	*cordi;

	tile_map = malloc(sizeof(t_tile_map));
	if (tile_map == NULL)
		return ;
	cordi = malloc(sizeof(t_cordi));
	if (cordi == NULL)
		return ;
	cordi->row = 0;
	while (cordi->row < char_map->row_size)
	{
		tile_map->map_cordi[cordi->row] = malloc(sizeof(void *) * char_map->col_size);
		if (tile_map->map_cordi[cordi->row] == NULL)
		{
			while (cordi->row >= 0)
				free(tile_map->map_cordi[cordi->row--]);
			free(tile_map);
			return (NULL);
		}

		cordi->col = 0;
		while (cordi->col < char_map->col_size)
		{
			if (char_map->map_cordi[cordi->row][cordi->col] == '1')
				tile_map->map_cordi[cordi->row][cordi->col] = tile_data->rock;
			else if (char_map->map_cordi[cordi->row][cordi->col] == '0')
				tile_map->map_cordi[cordi->row][cordi->col] = tile_data->grass;
			else if (char_map->map_cordi[cordi->row][cordi->col] == 'P')
				tile_map->map_cordi[cordi->row][cordi->col] = tile_data->person;
			else if (char_map->map_cordi[cordi->row][cordi->col] == 'C')
				tile_map->map_cordi[cordi->row][cordi->col] = tile_data->chest;
			else if (char_map->map_cordi[cordi->row][cordi->col] == 'E')
				tile_map->map_cordi[cordi->row][cordi->col] = tile_data->door;
			cordi->col++;
		}
		cordi->row++;
	}
	return (tile_map);
}

void draw_tile_map(t_win_data *win_data, t_tile_data *tile_data, t_tile_map	*tile_map)
{
	t_cordi *cordi;
	cordi->row = 0;
	while (cordi->row <= tile_map->row_size)
	{
		cordi->col = 0;
		while (cordi->col <= tile_map->col_size)
			mlx_put_image_to_window (win_data->mlx_ptr, win_data->win_ptr, tile_map->map_cordi[cordi->row][cordi->col], tile_data->tile_location[cordi->row][cordi->col][0], tile_data->tile_location[cordi->row][cordi->col++][1]);
		cordi->row++;
	}
}

t_tile_data	*init_tiles(t_win_data *win_data)
{
	t_tile_data	*tile_data;
	tile_data = malloc(sizeof(t_tile_data));
	if (tile_data == NULL)
		return (NULL);
	tile_data->tile_location = set_tile_location(tile_data);
	tile_data->rock = open_xpm(win_data, NULL, "rock");
	tile_data->grass = open_xpm(win_data, NULL, "grass");
	tile_data->door = open_xpm(win_data, NULL, "door");
	tile_data->chest = open_xpm(win_data, NULL, "chest");
	tile_data->person = open_xpm(win_data, NULL, "person");
	return (tile_data);
}

int	***set_tile_location(t_tile_data *tile_data)
{
	int row;
	int col;

	tile_data->tile_location = malloc(sizeof(int **) * 10);
	if (tile_data == NULL)
		return (NULL);
	row = 0;
	while (row < 10)
	{
		tile_location[row] = malloc(sizeof(int *) * 10);
		if (tile_location[row] == NULL)
		{
			while (row >= 0)
			{
				col = 0;
				while (col < 10)
					free(tile_location[row][col++]);
				free(tile_location[row]);
				row--;
			}
			free(tile_location);
			return (NULL);
		}
		col = 0;
		while (col < 10)
		{
			tile_location[row][col] = malloc(sizeof(int) * 2);
			if (tile_location[row][col] == NULL)
			{
				while (--row >= 0)
				{
					col = 0;
					while (col < 10)
					{
						free(tile_location[row][col]);
						col++;
					}
					free(tile_location[row]);
				}
				free(tile_location);
				return (NULL);
			}
			tile_location[row][col][0] = TILE_LEN * row;
			tile_location[row][col][1] = TILE_LEN * col;
			col++;
		}
		row++;
	}
	return (tile_location);
}

void	*open_xpm(t_win_data *win_data, void *single_tile, char *tile_name)
{
	char *file_path = template_literal("./tile/.xpm", tile_name, 7);
	single_tile = mlx_xpm_file_to_image(win_data->mlx_ptr, file_path, TILE_LEN, TILE_LEN);
	free(file_path);
	return (single_tile);
}





t_char_map *validate_map(void)
{
	int fd;
	char	*total_line;
	char	*single_line;
	char	*map_str;
	char buf[5];
	t_char_map *char_map;
	char_map = malloc(sizeof(t_char_map));
	if (char_map == NULL)
		return (NULL);
	fd = open("map.ber", O_RDONLY);
	map_str = malloc(sizeof(char) * 1);
	if (map_str == NULL)
		return (NULL);
	map_str[0] = '\0';
	while (read(fd, buf, 5) > 0)
	{
		buf[5] = '\0';
		map_str = join_s(map_str, buf);
	}
	printf("%s\n", map_str);
	if (!is_square(map_str))
		return (NULL);
	if (is_wall(map_str))
		return (NULL);
	if (is_there(map_str, EXIT) != 1)
		return (NULL);
	if (is_there(map_str, PERSON) != 1)
		return (NULL);
	char_map->arr_map = set_map_str_to_arr(map_str)->arr_map;
	return (char_map);
}

t_char_map	*set_map_str_to_arr(char *map_str)
{
	t_char_map	*char_map;
	int row;
	int col;
	int index;
	char_map = malloc(sizeof(t_char_map));
	if (char_map == NULL)
		return (NULL);
	char_map->row_size = 0;
	char_map->col_size = 0;
	row = 0;
	col = 0;
	index = 0;
	while (map_str[index] != '\0')
	{
		if(map_str[index] == '\n')
			char_map->row_size++;
		index++;
	}
	char_map->col_size = index / char_map->row_size;
	char_map->arr_map = malloc(sizeof(char *) * char_map->row_size);
	if (char_map->arr_map == NULL)
		return (NULL);
	while (row < char_map->row_size)
	{
		char_map->arr_map[row] = malloc(sizeof(char) * char_map->col_size);
		if (char_map->arr_map[row] == NULL)
		{
			while (row-- >= 0)
				free(char_map->arr_map[row]);
			free(char_map->arr_map);
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
			char_map->arr_map[row][col] = map_str[index];
			index++;
			col++;
		}
		index++;
		row++;
	}
	return (char_map);
}

bool	is_square(char *map_str)
{
	int index;
	int	line_len;
	int	count_newline;
	index = 0;
	line_len = 0;
	count_newline = 0;
	while (map_str[index] != '\0')
	{
		if (map_str[index] == '\n')
			count_newline++;
		index++;
	}
	if (count_newline < 3)
		return (false);
	index = 0;
	while (map_str[line_len++] != '\n')
		;
	while (map_str[index] != '\0')
	{
		if (index % line_len == 0 && (map_str[index] != '\n' || map_str[index] != '\0'))
				return (false);
		index++;
	}
	return (true);
}

bool	is_wall(char *map_str)
{
	int index;
	int	line_len;
	index = 0;
	line_len = 0;
	while (map_str[line_len++] != '\n')
		;
	while (index < line_len)
	{
		if (map_str[index++] != '1')
			return (false);
	}
	while (map_str[index] != '\0')
	{
		index++;
		if (map_str[index] != '1' || map_str[index + line_len] != '1')
			return (false);
		index += line_len;
	}
	return (true);
}

int	is_there(char *map_str, char c)
{
	int index;
	int	count_c;
	index = 0;
	count_c = 0;
	while (map_str[index] != '\0')
	{
		if (map_str[index] == c)
			count_c++;
		index++;
	}
	return (count_c);
}


