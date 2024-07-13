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
	map = malloc(sizeof(void *) * 10 * 10);
	if (map == NULL)
		return (NULL);
	int row;
	int col;
	row = 0;
	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10)
		{
			map[row][col] = tile_data->rock;
			row++;
		}
		col++;
	}
	return (map);
}

void draw_map(t_win_data *win_data, t_tile *tile_data, void ***map)
{
	int row;
	int col;
	row = 0;
	col = 0;
	while (col <= 9)
	{
		row = 0;
		while (row <= 9)
		{
			mlx_put_image_to_window (win_data->mlx_ptr, win_data->win_ptr, tile_data->rock, tile_data->tile_location[row][col][0], tile_data->tile_location[row][col][1]);
			map[row][col] = tile_data->rock;
			row++;
		}
		col++;
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
	tile_location = malloc(sizeof(int) * 10 * 10 * 2);
	int row;
	int col;
	row = 0;
	col = 0;

	while (col <= 9)
	{
		row = 0;
		while (row <= 9)
		{
			tile_location[row][col][0] = 20 * row;
			tile_location[row][col][1] = 20 * col;
			row++;
		}
		col++;
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
