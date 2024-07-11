#include "so_long.h"

void	init_win_data(t_win_data*win_data)
{
	win_data->title = "so_long";
	win_data->size_x = 200;
	win_data->size_y = 200;
	win_data->mlx_ptr = mlx_init();
	win_data->win_ptr = mlx_new_window(win_data->mlx_ptr, win_data->size_x, win_data->size_y, win_data->title);
	mlx_loop(win_data);
	return ;
}

t_tile	*init_tile(t_win_data *win_data)
{
	t_tile	*tile_data;
	tile_data = malloc(sizeof(t_tile));
	if (tile_data == NULL)
		return (NULL);
	printf("%s\n", NAME_TO_STRING(door));
	set_tile(win_data, tile_data->door, NAME_TO_STRING(door));
	return (tile_data);
}


void	*set_tile(t_win_data *win_data, void *box, char *str)
{
	int tile_len = 20;
	box = mlx_xpm_file_to_image(win_data->mlx_ptr, template_literal("./tile/.xpm", str, 7), &tile_len, &tile_len);

	return (box);
}

// void	set_map(t_win_data *win_data, t_tile *tile)
// {
// 	size_t map[10][10][2];
// 	size_t row;
// 	size_t col;
// 	row = 0;
// 	col = 0;
// 	while (col <= 9)
// 	{
// 		row = 0;
// 		while (row <= 9)
// 		{
// 			map[row][col][0] = row * tile->tile_len;
// 			map[row][col][1] = col * tile->tile_len;
// 			row++;
// 		}
// 		col++;
// 	}
// 	size_t is_error;
// 	is_error = mlx_put_image_to_window(win_data->mlx_ptr, win_data->win_ptr, tile->door, map[0][0][0], map[0][0][1]);
// 	// is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, chest, map[1][0][0], map[1][0][1]);
// 	// is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, grass, map[0][2][0], map[0][2][1]);
// 	// is_error = mlx_put_image_to_window(mlx_ptr, win_ptr, rock, map[2][1][0], map[2][1][1]);

// }

char	*template_literal(char *line, char *word, size_t location)
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
