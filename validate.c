#include "so_long.h"

int main(void)
{
	int fd = open("map.ber", O_RDONLY);
	t_total_data *total_data;
	total_data = malloc(sizeof(t_total_data));
	total_data->map_data = malloc(sizeof(t_map_data));
	set_map_str(fd, total_data);
	printf("is square : %d\n", is_square(total_data->map_data));
	printf("is wall : %d\n", is_wall(total_data->map_data));
	printf("is proper chars : %d\n", is_proper_chars(total_data->map_data));
	printf("is possible : %d\n", is_possible(total_data->map_data));
	return (0);	
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

void	*set_map_str(int fd, t_total_data *total_data)
{
	int	read_return;
	char buf[5];
	total_data->map_data->map_str = malloc(sizeof(char) * 1);
	if (total_data->map_data->map_str == NULL)
		return (NULL);
	total_data->map_data->map_str[0] = '\0';
	while (1)
	{
		read_return = read(fd, buf, 5);
		buf[read_return] = '\0';
		total_data->map_data->map_str = join_s(total_data->map_data->map_str, buf);
		if (read_return < 5)
			break;
	}
	// free(buf);
	printf("%s\n", total_data->map_data->map_str);
	return (NULL);
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


bool	backtracking(t_char_map *char_map)
{
	t_cordi	*person;
	person = get_cordi(char_map, PERSON);
	return (is_possible(char_map, person));
}

t_cordi	*get_cordi(t_char_map *char_map, char c)
{
	t_cordi	*cordi;

	cordi->row = 0;
	while (cordi->row < char_map->row_size)
	{
		cordi->col = 0;
		while (cordi->col < char_map->col_size)
		{
			if (char_map->map_cordi[cordi->row][cordi->col] == c)
				return (cordi);
			cordi->col++;
		}
		cordi->row++;
	}
	return (NULL);
}

bool	is_possible(t_char_map *char_map, t_cordi *person)
{
	if (char_map->map_cordi[person->row + 1][person->col] == EXIT)
		return (true);
	else if (char_map->map_cordi[person->row - 1][person->col] == EXIT)
		return (true);
	else if (char_map->map_cordi[person->row][person->col + 1] == EXIT)
		return (true);
	else if (char_map->map_cordi[person->row][person->col - 1] == EXIT)
		return (true);
	else if (char_map->map_cordi[person->row + 1][person->col] == EMPTY)
	{
		char_map->map_cordi[person->row][person->col] == WALL;
		person->row += 1;
		return (is_possible(char_map, person));
	}
	else if (char_map->map_cordi[person->row - 1][person->col] == EMPTY)
	{
		char_map->map_cordi[person->row][person->col] == WALL;
		person->row -= 1;
		return (is_possible(char_map, person));
	}
	else if (char_map->map_cordi[person->row][person->col + 1] == EMPTY)
	{
		char_map->map_cordi[person->row][person->col] == WALL;
		person->col += 1;
		return (is_possible(char_map, person));
	}
	else if (char_map->map_cordi[person->row][person->col - 1] == EMPTY)
	{
		char_map->map_cordi[person->row][person->col] == WALL;
		person->col += 1;
		return (is_possible(char_map, person));
	}
	else
		return (false);
}

