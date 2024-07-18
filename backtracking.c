#include "so_long.h"

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
		person->row += 1;
		return (is_possible(char_map, person));
	}
	else if (char_map->map_cordi[person->row - 1][person->col] == EMPTY)
	{
		person->row -= 1;
		return (is_possible(char_map, person));
	}
	else if (char_map->map_cordi[person->row][person->col + 1] == EMPTY)
	{
		person->col += 1;
		return (is_possible(char_map, person));
	}
	else if (char_map->map_cordi[person->row][person->col - 1] == EMPTY)
	{
		person->col += 1;
		return (is_possible(char_map, person));
	}
	return (false);
}

