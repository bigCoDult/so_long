#include "so_long.h"
void	init_win_data(t_win_data*win_data)
{
	win_data->title = "so_long";
	win_data->size_x = 500;
	win_data->size_y = 500;
	win_data->mlx_ptr = mlx_init();
	win_data->win_ptr = mlx_new_window(win_data->mlx_ptr, win_data->size_x, win_data->size_y, win_data->title);
	return ;
}








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




void	deal_map(t_win_data *win_data)
{
	void	***tile_map;
	t_tile	*tile_data;
	t_arr_map_data *arr_map_data;
	tile_data = malloc(sizeof(t_tile));
	if (tile_data == NULL)
		return ;
	arr_map_data = malloc(sizeof(t_arr_map_data));
	if (arr_map_data == NULL)
		return ;
	arr_map_data = validate_map();
	tile_data = init_tiles(win_data);
	tile_map = set_tile_map(win_data, tile_data, arr_map_data);
	draw_tile_map(win_data, tile_data, tile_map);
	return ;
}

void	***set_tile_map(t_win_data *win_data, t_tile *tile_data, t_arr_map_data *arr_map_data)
{
	void	***tile_map;
	int		row;
	int		col;

	tile_map = malloc(sizeof(void **) * arr_map_data->row_len);
	if (tile_map == NULL)
		return (NULL);

	row = 0;
	while (row < 10)
	{
		tile_map[row] = malloc(sizeof(void *) * arr_map_data->col_len);
		if (tile_map[row] == NULL)
		{
			while (--row >= 0)
				free(tile_map[row]);
			free(tile_map);
			return (NULL);
		}

		col = 0;
		while (col < 10)
		{
			if (arr_map_data->arr_map[row][col] == '1')
				tile_map[row][col] = tile_data->rock;
			else if (arr_map_data->arr_map[row][col] == '0')
				tile_map[row][col] = tile_data->grass;
			else if (arr_map_data->arr_map[row][col] == 'E')
				tile_map[row][col] = tile_data->door;
			else if (arr_map_data->arr_map[row][col] == 'P')
				tile_map[row][col] = tile_data->rock;
			// tile_map[row][col] = tile_data->rock;
			col++;
		}
		row++;
	}
	return (tile_map);
}

void draw_tile_map(t_win_data *win_data, t_tile *tile_data, void ***tile_map)
{
	int row;
	int col;
	row = 0;
	col = 0;
	while (row <= 9)
	{
		col = 0;
		while (col <= 9)
		{
			// mlx_put_image_to_window (win_data->mlx_ptr, win_data->win_ptr, tile_map[row][col], tile_data->tile_location[row][col][0], tile_data->tile_location[row][col][1]);
			mlx_put_image_to_window (win_data->mlx_ptr, win_data->win_ptr, tile_data->rock, tile_data->tile_location[row][col][0], tile_data->tile_location[row][col][1]);
			col++;
		}
		row++;
	}
}

t_tile	*init_tiles(t_win_data *win_data)
{
	t_tile	*tile_data;
	tile_data = malloc(sizeof(t_tile));
	if (tile_data == NULL)
		return (NULL);
	tile_data->tile_location = set_tile_location();
	tile_data->grass = open_xpm(win_data, NULL, NAME_TO_STRING(grass));
	tile_data->chest = open_xpm(win_data, NULL, NAME_TO_STRING(chest));
	tile_data->door = open_xpm(win_data, NULL, NAME_TO_STRING(door));
	tile_data->rock = open_xpm(win_data, NULL, NAME_TO_STRING(rock));
	return (tile_data);
}

int	***set_tile_location(void)
{
	int	***tile_location;
	int row;
	int col;

	tile_location = malloc(sizeof(int **) * 10);
	if (tile_location == NULL)
		return (NULL);
	row = 0;
	while (row < 10)
	{
		tile_location[row] = malloc(sizeof(int *) * 10);
		if (tile_location[row] == NULL)
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
			tile_location[row][col][0] = 20 * row;
			tile_location[row][col][1] = 20 * col;
			col++;
		}
		row++;
	}
	return (tile_location);
}

void	*open_xpm(t_win_data *win_data, void *single_tile, char *tile_name)
{
	int tile_len = 20;
	char *file_path = template_literal("./tile/.xpm", tile_name, 7);
	single_tile = mlx_xpm_file_to_image(win_data->mlx_ptr, file_path, &tile_len, &tile_len);
	free(file_path);
	return (single_tile);
}

t_arr_map_data *validate_map(void)
{
	int fd;
	char	*total_line;
	char	*single_line;
	char	*map_str;
	char buf[5];
	t_arr_map_data *arr_map_data;
	arr_map_data = malloc(sizeof(t_arr_map_data));
	if (arr_map_data == NULL)
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
	// if (!is_square(map_str))
	// 	return (NULL);
	// if (is_wall(map_str))
	// 	return (NULL);
	// if (is_possible(map_str))
	// 	return (NULL);
	arr_map_data->arr_map = set_str_to_2d_arr(map_str)->arr_map;
	return (arr_map_data);
}

t_arr_map_data	*set_str_to_2d_arr(char *map_str)
{
	t_arr_map_data	*arr_map_data;
	int row;
	int col;
	int index;
	arr_map_data = malloc(sizeof(t_arr_map_data));
	if (arr_map_data == NULL)
		return (NULL);
	arr_map_data->row_len = 0;
	arr_map_data->col_len = 0;
	row = 0;
	col = 0;
	index = 0;
	while (map_str[index] != '\0')
	{
		if(map_str[index] == '\n')
			arr_map_data->row_len++;
		index++;
	}
	arr_map_data->col_len = index / arr_map_data->row_len;
	arr_map_data->arr_map = malloc(sizeof(char *) * arr_map_data->row_len);
	if (arr_map_data->arr_map == NULL)
		return (NULL);
	while (row < arr_map_data->row_len)
	{
		arr_map_data->arr_map[row] = malloc(sizeof(char) * arr_map_data->col_len);
		if (arr_map_data->arr_map[row] == NULL)
		{
			while (row-- >= 0)
				free(arr_map_data->arr_map[row]);
			free(arr_map_data->arr_map);
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
			arr_map_data->arr_map[row][col] = map_str[index];
			index++;
			col++;
		}
		index++;
		row++;
	}
	return (arr_map_data);
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

bool	is_possible(char *map_str)
{
	return (true);
}


