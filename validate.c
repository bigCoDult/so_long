#include "so_long.h"

bool	validate_map(t_map_data *map_data)
{
	if (is_square(map_data) && is_wall(map_data) && is_proper_chars(map_data) && backtracking(map_data))
		return (true);
	return (false);

}
bool	is_square(t_map_data *map_data)
{	
	int index;
	int	first_line;
	int current;
	
	index = 0;
	first_line = 0;
	current = 0;
	
	while (map_data->map_str[first_line] != '\n' && map_data->map_str[first_line] != '\0')
		first_line++;
	index = first_line + 1;
	while (map_data->map_str[index] != '\0')
	{
		current = index;
		while (map_data->map_str[current] != '\n' && map_data->map_str[current] != '\0')
			current++;
		if (current - index != first_line)
			return (false);
		index += first_line;
		if (map_data->map_str[index] == '\n')
			index++;
	}
	return (true);
}

bool	is_wall(t_map_data *map_data)
{
	int index;
	int	first_line;
	int current;
	
	index = 0;
	first_line = 0;
	current = 0;
	
	while (map_data->map_str[first_line] != '\n' && map_data->map_str[first_line] != '\0')
		first_line++;
	while (index < first_line)
	{
		if (map_data->map_str[index] != WALL)
			return (false);
		index++;
	}
	while (map_data->map_str[index] != '\0')
	{
		index++;
		if (map_data->map_str[index] != WALL || map_data->map_str[index + first_line - 1] != WALL)
			return (false);
		index += first_line;
	}
	index -= first_line;
	while (map_data->map_str[index] != '\0')
	{
		if (map_data->map_str[index] != WALL)
			return (false);
		index++;
	}
	
	return (true);
}

bool	is_proper_chars(t_map_data *map_data)
{
	int index;
	int	count_person;
	int	count_exit;
	int	count_collect;
	
	index = 0;
	count_person = 0;
	count_exit = 0;
	count_collect = 0;
	while (map_data->map_str[index] != '\0')
	{
		if (map_data->map_str[index] == PERSON)
			count_person++;
		else if (map_data->map_str[index] == EXIT)
			count_exit++;
		else if (map_data->map_str[index] == COLLECT)
			count_collect++;
		else if (map_data->map_str[index] == WALL || map_data->map_str[index] == EMPTY || map_data->map_str[index] == '\n')
			;
		else
			return (false);
		index++;
	}
	if (count_person != 1 || count_exit != 1 || count_collect < 1)
		return (false);
	return (true);
}










bool	backtracking(t_map_data *map_data)
{
	map_data->person = malloc(sizeof(t_cordi));
	if (map_data->person == NULL)
		return (false);
	map_data->person = get_cordi(map_data, PERSON);
	return (is_possible(map_data));
}

t_cordi	*get_cordi(t_map_data *map_data, char c)
{
	while (map_data->person->row < map_data->row_size)
	{
		map_data->person->col = 0;
		while (map_data->person->col < map_data->col_size)
		{
			if (map_data->char_map[map_data->person->row][map_data->person->col] == c)
				return (map_data->person);
			map_data->person->col++;
		}
		map_data->person->row++;
	}
	return (NULL);
}
bool	is_possible(t_map_data *map_data)
{
	int row;
	int col;
	
	while (row < map_data->row_size)
	{
		col = 0;
		while (col < map_data->col_size)
		{
			if (map_data->char_map[row][col] == PERSON)
			{
				map_data->person->row = row;
				map_data->person->col = col;
			}
			col++;
		}
		row++;
	}
	if (map_data->char_map[map_data->person->row + 1][map_data->person->col] == EXIT)
		return (true);
	else if (map_data->char_map[map_data->person->row - 1][map_data->person->col] == EXIT)
		return (true);
	else if (map_data->char_map[map_data->person->row][map_data->person->col + 1] == EXIT)
		return (true);
	else if (map_data->char_map[map_data->person->row][map_data->person->col - 1] == EXIT)
		return (true);
	else if (map_data->char_map[map_data->person->row + 1][map_data->person->col] == EMPTY)
	{
		map_data->char_map[map_data->person->row][map_data->person->col] == WALL;
		map_data->person->row += 1;
		return (is_possible(map_data));
	}
	else if (map_data->char_map[map_data->person->row - 1][map_data->person->col] == EMPTY)
	{
		map_data->char_map[map_data->person->row][map_data->person->col] == WALL;
		map_data->person->row -= 1;
		return (is_possible(map_data));
	}
	else if (map_data->char_map[map_data->person->row][map_data->person->col + 1] == EMPTY)
	{
		map_data->char_map[map_data->person->row][map_data->person->col] == WALL;
		map_data->person->col += 1;
		return (is_possible(map_data));
	}
	else if (map_data->char_map[map_data->person->row][map_data->person->col - 1] == EMPTY)
	{
		map_data->char_map[map_data->person->row][map_data->person->col] == WALL;
		map_data->person->col += 1;
		return (is_possible(map_data));
	}
	else
		return (false);
}

