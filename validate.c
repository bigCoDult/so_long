#include "so_long.h"

bool	validate_map(t_map_d *map_d)
{
	if (is_square(map_d) && is_wall(map_d) && is_proper_chars(map_d))
		return (true);
	return (false);
}
bool	is_square(t_map_d *map_d)
{	
	int index;
	int	first_line;
	int current;
	
	index = 0;
	first_line = 0;
	current = 0;
	
	while (map_d->map_str[first_line] != '\n' && map_d->map_str[first_line] != '\0')
		first_line++;
	index = first_line + 1;
	while (map_d->map_str[index] != '\0')
	{
		current = index;
		while (map_d->map_str[current] != '\n' && map_d->map_str[current] != '\0')
			current++;
		if (current - index != first_line)
			return (false);
		index += first_line;
		if (map_d->map_str[index] == '\n')
			index++;
	}
	return (true);
}

bool	is_wall(t_map_d *map_d)
{
	int index;
	int	first_line;
	int current;
	
	index = 0;
	first_line = 0;
	current = 0;
	while (map_d->map_str[first_line] != '\n' && map_d->map_str[first_line] != '\0')
		first_line++;
	while (index < first_line)
	{
		if (map_d->map_str[index] != WALL)
			return (false);
		index++;
	}
	while (map_d->map_str[index] != '\0')
	{
		index++;
		if (map_d->map_str[index] != WALL || map_d->map_str[index + first_line - 1] != WALL)
			return (false);
		index += first_line;
	}
	index -= first_line;
	while (map_d->map_str[index] != '\0')
	{
		if (map_d->map_str[index] != WALL)
			return (false);
		index++;
	}
	return (true);
}

bool	is_proper_chars(t_map_d *map_d)
{
	int index;
	int	count_person;
	int	count_exit;
	
	index = 0;
	count_person = 0;
	count_exit = 0;
	map_d->c_c = 0;
	while (map_d->map_str[index] != '\0')
	{
		if (map_d->map_str[index] == PERSON)
			count_person++;
		else if (map_d->map_str[index] == EXIT)
			count_exit++;
		else if (map_d->map_str[index] == COLLECT)
			map_d->c_c++;
		else if (map_d->map_str[index] == WALL || map_d->map_str[index] == EMPTY || map_d->map_str[index] == '\n')
			;
		else
			return (false);
		index++;
	}
	if (count_person != 1 || count_exit != 1 || map_d->c_c < 1)
		return (false);
	return (true);
}

t_cor	get_cor(t_map_d *map_d, char c)
{
	t_cor	person;
	person = (t_cor){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < map_d->row_size)
	{
		person.c = 0;
		while (person.c < map_d->col_size)
		{
			if (map_d->c_map[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return (t_cor){-1, -1};
}

	// int print;
	// print = 0;
	// printf("\n");
	// printf("c_c : %d\n", map_d->c_c);
	// while (print < map_d->row_size)
	// 	printf("vali_map : %s\n", map_d->vali_map[print++]);
bool	is_possible(t_map_d *map_d, t_cor person)
{
	if (person.r < 0 || person.r > map_d->row_size || person.c < 0 || person.c > map_d->col_size)
		return (false);	
	if (map_d->c_c == 0)
	{
		if (map_d->vali_map[person.r][person.c] == WALL || map_d->vali_map[person.r][person.c] == '/')
			return (false);
		if (map_d->vali_map[person.r][person.c] == EXIT)
			return (true);
		map_d->vali_map[person.r][person.c] = '/';
	}
	else
	{
		if (map_d->vali_map[person.r][person.c] == WALL || map_d->vali_map[person.r][person.c] == '\\')
			return (false);
		if (map_d->vali_map[person.r][person.c] == COLLECT)
			map_d->c_c--;
		if (map_d->vali_map[person.r][person.c] != EXIT)
			map_d->vali_map[person.r][person.c] = '\\';
	}

	if (is_possible(map_d, (t_cor){person.r + 1, person.c}) \
		|| is_possible(map_d, (t_cor){person.r - 1, person.c}) \
		|| is_possible(map_d, (t_cor){person.r, person.c + 1}) \
		|| is_possible(map_d, (t_cor){person.r, person.c - 1}))
		return (true);
	return (false);
}
















