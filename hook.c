/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 12:54:14 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_tot *tot)
{
	void	*param;

	param = (void *)tot;
	draw_map(tot);
	is_proper_chars(tot->map_d);
	mlx_key_hook(tot->win_data->win_ptr, &move_person, param);
	return ;
}

int	move_person(int key, void *param)
{
	t_tot	*tot;
	int		step;
	t_cor	person;

	step = 0;
	tot = (t_tot *)param;
	person = get_cor(tot->map_d, 'P');
	if (key == KEY_ESC)
		mlx_loop_end(tot->win_data->mlx_ptr);
	else
		move_way(key, person, tot);
	return (0);
}

void	destroy_tiles(t_tot *tot)
{
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->rock);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->grass);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->person);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->chest);
	mlx_destroy_image (tot->win_data->mlx_ptr, tot->tile_data->door);
}

int	end_game(t_tot *tot)
{
	int	a;
	int	b;

	a = tot->map_d->row_size;
	b = a;
	destroy_tiles(tot);
	mlx_destroy_window(tot->win_data->mlx_ptr, tot->win_data->win_ptr);
	mlx_destroy_display(tot->win_data->mlx_ptr);
	while (a--)
		free(tot->map_d->c_map[a]);
	free(tot->map_d->c_map);
	while (b--)
		free(tot->map_d->vali_map[b]);
	free(tot->map_d->vali_map);
	free(tot->map_d->map_str);
	free(tot->map_d);
	free(tot->tile_data);
	free(tot->win_data->mlx_ptr);
	free(tot->win_data);
	free(tot);
	return (0);
}

int	move_way(int key, t_cor person, t_tot *tot)
{
	t_cor	way;

	way = (t_cor){0, 0};
	if (key == KEY_W || key == KEY_UP)
		way.r = -1;
	else if (key == KEY_S || key == KEY_DOWN)
		way.r = 1;
	else if (key == KEY_A || key == KEY_LEFT)
		way.c = -1;
	else if (key == KEY_D || key == KEY_RIGHT)
		way.c = 1;
	person.r += way.r;
	person.c += way.c;
	if (tot->map_d->c_map[person.r][person.c] == WALL)
		return (0);
	if (tot->map_d->c_map[person.r][person.c] == COLLECT)
		tot->map_d->c_c--;
	if (tot->map_d->c_map[person.r][person.c] == EXIT && tot->map_d->c_c != 0)
		return (0);
	if (tot->map_d->c_map[person.r][person.c] == EXIT && tot->map_d->c_c == 0)
		mlx_loop_end(tot->win_data->mlx_ptr);
	tot->map_d->c_map[person.r - way.r][person.c - way.c] = '0';
	tot->map_d->c_map[person.r][person.c] = 'P';
	draw_map(tot);
}
