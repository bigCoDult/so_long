#include "so_long.h"

bool	validate_map(t_map_data *map_data)
{
	// if (is_square(map_data) && is_wall(map_data))
	if (is_square(map_data) && is_wall(map_data) && is_proper_chars(map_data))
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
	
	index = 0;
	count_person = 0;
	count_exit = 0;
	map_data->count_collect = 0;
	while (map_data->map_str[index] != '\0')
	{
		if (map_data->map_str[index] == PERSON)
			count_person++;
		else if (map_data->map_str[index] == EXIT)
			count_exit++;
		else if (map_data->map_str[index] == COLLECT)
			map_data->count_collect++;
		else if (map_data->map_str[index] == WALL || map_data->map_str[index] == EMPTY || map_data->map_str[index] == '\n')
			;
		else
			return (false);
		index++;
	}
	if (count_person != 1 || count_exit != 1 || map_data->count_collect < 1)
		return (false);
	return (true);
}

t_cordi	*get_cordi(t_map_data *map_data, char c)
{
	t_cordi	*person;
	person = malloc(sizeof(t_cordi));
	if (person == NULL)
		return (NULL);
	person->row = 0;
	person->col = 0;
	while (person->row < map_data->row_size)
	{
		person->col = 0;
		while (person->col < map_data->col_size)
		{
			if (map_data->char_map[person->row][person->col] == c)
				return (person);
			person->col++;
		}
		person->row++;
	}
	free(person);
	return (NULL);
}








bool	is_possible(t_map_data *map_data, t_cordi *person)
{
	int print;
	print = 0;
	printf("\n");
	printf("count_collect : %d\n", map_data->count_collect);
	while (print < map_data->row_size)
		printf("vali_map : %s\n", map_data->vali_map[print++]);
	
	
	
	
	
	if (person->row < 0 || person->row > map_data->row_size || person->col < 0 || person->col > map_data->col_size)
		return (false);
	
	if (map_data->count_collect == 0)
	{
		if (map_data->vali_map[person->row][person->col] == WALL || map_data->vali_map[person->row][person->col] == '/')
			return (false);
		if (map_data->vali_map[person->row][person->col] == EXIT)
			return (true);
		map_data->vali_map[person->row][person->col] = '/';
	}
	else
	{
		if (map_data->vali_map[person->row][person->col] == WALL || map_data->vali_map[person->row][person->col] == '\\')
			return (false);
		if (map_data->vali_map[person->row][person->col] == COLLECT)
			map_data->count_collect--;
		if (map_data->vali_map[person->row][person->col] != EXIT)
			map_data->vali_map[person->row][person->col] = '\\';
	}

	if (is_possible(map_data, &(t_cordi){person->row + 1, person->col}) \
		|| is_possible(map_data, &(t_cordi){person->row - 1, person->col}) \
		|| is_possible(map_data, &(t_cordi){person->row, person->col + 1}) \
		|| is_possible(map_data, &(t_cordi){person->row, person->col - 1}))
		return (true);
	return (false);
}
















