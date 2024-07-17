#include "so_long.h"

bool	backtracking(t_arr_map_data *arr_map_data)
{
	t_cordi	*person;
	person = get_cordi(arr_map_data, PERSON);
	return (is_possible(arr_map_data, person));
}

t_cordi	*get_cordi(t_arr_map_data *arr_map_data, char c)
{
	t_cordi	*cordi;

	cordi->row = 0;
	while (cordi->row < arr_map_data->row_len)
	{
		cordi->col = 0;
		while (cordi->col < arr_map_data->col_len)
		{
			if (arr_map_data->arr_map[cordi->row][cordi->col] == c)
				return (cordi);
			cordi->col++;
		}
		cordi->row++;
	}
	return (NULL);
}

bool	is_possible(t_arr_map_data *arr_map_data, t_cordi *person)
{
	if (arr_map_data->arr_map[person->row + 1][person->col] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person->row - 1][person->col] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person->row][person->col + 1] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person->row][person->col - 1] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person->row + 1][person->col] == EMPTY)
	{
		person->row += 1;
		return (is_possible(arr_map_data, person));
	}
	else if (arr_map_data->arr_map[person->row - 1][person->col] == EMPTY)
	{
		person->row -= 1;
		return (is_possible(arr_map_data, person));
	}
	else if (arr_map_data->arr_map[person->row][person->col + 1] == EMPTY)
	{
		person->col += 1;
		return (is_possible(arr_map_data, person));
	}
	else if (arr_map_data->arr_map[person->row][person->col - 1] == EMPTY)
	{
		person->col += 1;
		return (is_possible(arr_map_data, person));
	}
	return (false);
}

