/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 14:31:43 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_tot *tot)
{
	void	*param;

	param = (void *)tot;
	draw_map(tot);
	is_proper_chars(tot->map_d);
	mlx_key_hook(tot->w_d->w_p, &move_person, param);
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
		mlx_loop_end(tot->w_d->m_p);
	else
		move_way(key, person, tot);
	return (0);
}

void	destroy_tiles(t_tot *tot)
{
	mlx_destroy_image (tot->w_d->m_p, tot->t_d->rock);
	mlx_destroy_image (tot->w_d->m_p, tot->t_d->grass);
	mlx_destroy_image (tot->w_d->m_p, tot->t_d->person);
	mlx_destroy_image (tot->w_d->m_p, tot->t_d->chest);
	mlx_destroy_image (tot->w_d->m_p, tot->t_d->door);
}

int	end_game(t_tot *tot)
{
	int	a;
	int	b;

	a = tot->map_d->row_size;
	b = a;
	destroy_tiles(tot);
	mlx_destroy_window(tot->w_d->m_p, tot->w_d->w_p);
	mlx_destroy_display(tot->w_d->m_p);
	while (a--)
		free(tot->map_d->c_map[a]);
	free(tot->map_d->c_map);
	while (b--)
		free(tot->map_d->vali_map[b]);
	free(tot->map_d->vali_map);
	free(tot->map_d->str);
	free(tot->map_d);
	free(tot->t_d);
	free(tot->w_d->m_p);
	free(tot->w_d);
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
	if (tot->map_d->c_map[person.r][person.c] == W)
		return (0);
	if (tot->map_d->c_map[person.r][person.c] == C)
		tot->map_d->c_c--;
	if (tot->map_d->c_map[person.r][person.c] == E && tot->map_d->c_c != 0)
		return (0);
	if (tot->map_d->c_map[person.r][person.c] == E && tot->map_d->c_c == 0)
		mlx_loop_end(tot->w_d->m_p);
	tot->map_d->c_map[person.r - way.r][person.c - way.c] = '0';
	tot->map_d->c_map[person.r][person.c] = 'P';
	draw_map(tot);
}
