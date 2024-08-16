/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 23:22:44 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_tot *tot)
{
	void	*param;
	int		step;

	param = (void *)tot;
	draw_map(tot);
	is_proper_chars(tot->m_d);
	step = 0;
	mlx_key_hook(tot->w_d->w_p, &move_person, param);
	return ;
}

int	move_person(int key, void *param)
{
	t_tot	*tot;
	t_cor	person;

	tot = (t_tot *)param;
	person = get_cor(tot->m_d, 'P');
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
	int	rs;

	rs = tot->m_d->row_size;
	int a = is_square(tot->m_d);
	int b = is_w(tot->m_d);
	int c = is_proper_chars(tot->m_d);
	int d = tot->m_d->possible;
	if (a && b && c && d)
		destroy_tiles(tot);
	mlx_destroy_window(tot->w_d->m_p, tot->w_d->w_p);
	mlx_destroy_display(tot->w_d->m_p);
	// if (1)
	if (d)
	{
		while (rs--)
			free(tot->m_d->c_map[rs]);
		free(tot->m_d->c_map);
		rs = tot->m_d->row_size;
		while (rs--)
			free(tot->m_d->vali_map[rs]);
		free(tot->m_d->vali_map);
	}
	// if (a && b && c)
	free(tot->m_d->str);
	free(tot->m_d);
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
	if (tot->m_d->c_map[person.r][person.c] == W)
		return (0);
	if (tot->m_d->c_map[person.r][person.c] == C)
		tot->m_d->c_c--;
	if (tot->m_d->c_map[person.r][person.c] == E && tot->m_d->c_c != 0)
		return (0);
	if (tot->m_d->c_map[person.r][person.c] == E && tot->m_d->c_c == 0)
		mlx_loop_end(tot->w_d->m_p);
	tot->m_d->c_map[person.r - way.r][person.c - way.c] = Z;
	tot->m_d->c_map[person.r][person.c] = P;
	draw_map(tot);
}
