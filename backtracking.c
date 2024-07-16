#include "so_long.h"

bool	backtracking(t_arr_map_data *arr_map_data)
{
	int person[2];
	int exit[2];
	// int collect[2];
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

bool	is_possible(char *map_str, int *person, int *exit)
{

}


