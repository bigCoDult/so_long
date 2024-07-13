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
	t_tile	*tile_data;
	void	***map;
	tile_data = malloc(sizeof(t_tile));
	if (tile_data == NULL)
		return ;
	tile_data = init_tile(win_data);
	map = set_map(win_data, tile_data);
	draw_map(win_data, tile_data, map);
	return ;
}

void	***set_map(t_win_data *win_data, t_tile *tile_data)
{
	void	***map;
	int		row;
	int		col;

	map = malloc(sizeof(void **) * 10);
	if (map == NULL)
		return (NULL);

	row = 0;
	while (row < 10)
	{
		map[row] = malloc(sizeof(void *) * 10);
		if (map[row] == NULL)
		{
			while (--row >= 0)
				free(map[row]);
			free(map);
			return (NULL);
		}

		col = 0;
		while (col < 10)
		{
			map[row][col] = tile_data->rock;
			col++;
		}
		row++;
	}
	return (map);
}

void draw_map(t_win_data *win_data, t_tile *tile_data, void ***map)
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
			mlx_put_image_to_window (win_data->mlx_ptr, win_data->win_ptr, tile_data->rock, tile_data->tile_location[row][col][0], tile_data->tile_location[row][col][1]);
			map[row][col] = tile_data->rock;
			col++;
		}
		row++;
	}
}

t_tile	*init_tile(t_win_data *win_data)
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












char	**validate_map(void)
{
	int fd;
	char	*total_line;
	char	*single_line;
	char	*map_str;
	char buf[5];
	char **map_2d_arr;

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
	is_square(map_str);
	is_wall(map_str);
	is_possible(map_str);
	// set_map_to_2d_arr(map_str);
	return (map_2d_arr);
}

// char	**set_map_to_2d_arr(char *map_str)
// {
// 	char **map_2d_arr;
// 	int col;
// 	int row;
// 	while (map_str != '\0')

// 			vert_len++;
// 	map_2d_arr = malloc(sizeof(char *) * hori_len);


// }

bool is_square(char *map_str)
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

bool is_wall(char *map_str)
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


