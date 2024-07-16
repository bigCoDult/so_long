#include "so_long.h"

bool	backtracking(t_arr_map_data *arr_map_data)
{
	int person[2];
	int exit[2];
	// int collect[2];
	//벡터 구조체
	//xy좌표를 저장하는 구조체
	//가독성을 높일 수 있다
	*person = get_cordi(arr_map_data, PERSON);
	*exit = get_cordi(arr_map_data, EXIT);
	// *collect = get_cordi(arr_map_data, COLLECT);
	return (is_possible(arr_map_data, person, exit));
}

int	*get_cordi(t_arr_map_data *arr_map_data, char c)
{
	int row;
	int col;
	int	cordi[2];

	row = 0;
	while (row < arr_map_data->row_len)
	{
		col = 0;
		while (col < 10)
		{
			if (arr_map_data->arr_map[row][col] == c)
			{
				cordi[0] = row;
				cordi[1] = col;
				return (cordi);
			}
			col++;
		}
		row++;
	}
	return (NULL);
}

bool	is_possible(t_arr_map_data *arr_map_data, int *person, int *exit)
{
	int	person_row;
	int	person_col;
	person_row = person[0];
	person_col = person[1];
	if (arr_map_data->arr_map[person_row + 1][person_col] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person_row - 1][person_col] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person_row][person_col + 1] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person_row][person_col - 1] == EXIT)
		return (true);
	else if (arr_map_data->arr_map[person_row + 1][person_col] == EMPTY)
	{
		person[0] = person_row + 1;
		return (is_possible(arr_map_data, person, exit));
	}
	else if (arr_map_data->arr_map[person_row - 1][person_col] == EMPTY)
	{
		person[0] = person_row - 1;
		return (is_possible(arr_map_data, person, exit));
	}
	else if (arr_map_data->arr_map[person_row][person_col + 1] == EMPTY)
	{
		person[1] = person_col + 1;
		return (is_possible(arr_map_data, person, exit));
	}
	else if (arr_map_data->arr_map[person_row][person_col - 1] == EMPTY)
	{
		person[1] = person_col + 1;
		return (is_possible(arr_map_data, person, exit));
	}
	return (false);
}

