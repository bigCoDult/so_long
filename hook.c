/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 12:41:17 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_total_data *tot)
{
	void	*param;

	param = (void *)tot;
	draw_map(tot);
	is_proper_chars(tot->map_data);
	mlx_key_hook(tot->win_data->win_ptr, &move_person, param);
	return ;
}

int	move_person(int key, void *param)
{
	t_total_data	*tot;
	int						step;

	step = 0;
	tot = (t_total_data *)param;
	t_cordi person;
	person = get_cordi(tot->map_data, 'P');
	if (key == KEY_ESC)
	{
		// end_game(tot);
		mlx_loop_end(tot->win_data->mlx_ptr);
		return (0);
	}
	else
		move_way(key, person, tot);
	return (0);
}

void	destroy_tiles(t_total_data *tot)
{
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->rock);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->grass);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->person);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->chest);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->door);
}

int end_game(t_total_data *tot)
{
	int a = tot->map_data->row_size;
	int b = a;
	
	destroy_tiles(tot);
	mlx_destroy_window(tot->win_data->mlx_ptr, tot->win_data->win_ptr);
	mlx_destroy_display(tot->win_data->mlx_ptr);
	while (a--)
		free(tot->map_data->char_map[a]);
	free(tot->map_data->char_map);
	while (b--)
		free(tot->map_data->vali_map[b]);
	free(tot->map_data->vali_map);	
	free(tot->map_data->map_str);
	free(tot->map_data);
	free(tot->tile_data);	
	free(tot->win_data->mlx_ptr);
	free(tot->win_data);
	free(tot);
	return (0);	
}

int move_way(int key, t_cordi person, t_total_data *tot)
{
	int row;
	int col;
	row = 0;	
	col = 0;
	if (key == KEY_W || key == KEY_UP)
		row = -1;
	else if (key == KEY_S || key == KEY_DOWN)
		row = 1;
	else if (key == KEY_A || key == KEY_LEFT)
		col = -1;
	else if (key == KEY_D || key == KEY_RIGHT)
		col = 1;
	person.row += row;
	person.col += col;		
	if (tot->map_data->char_map[person.row][person.col] == WALL)
		return (0);
	if (tot->map_data->char_map[person.row][person.col] == COLLECT)
		tot->map_data->count_collect--;
	if (tot->map_data->char_map[person.row][person.col] == EXIT && tot->map_data->count_collect != 0)
		return (0);
	if (tot->map_data->char_map[person.row][person.col] == EXIT && tot->map_data->count_collect == 0)
		mlx_loop_end(tot->win_data->mlx_ptr);
	tot->map_data->char_map[person.row - row][person.col - col] = '0';
	tot->map_data->char_map[person.row][person.col] = 'P';
	draw_map(tot);
}
