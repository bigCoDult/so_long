/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 00:25:52 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_tt *tt)
{
	void	*param;
	int		step;

	step = 0;
	tt->m_d->step = 0;
	printf("step : %d\n", tt->m_d->step++);
	draw_map(tt);
	tt->m_d->exit = get_cor(tt->m_d, E);
	param = (void *)tt;
	is_proper_chars(tt->m_d);
	mlx_hook(tt->wd->wp, KeyPress, KeyPressMask, &move_person, param);
	mlx_hook(tt->wd->wp, 17, NoEventMask, &close_window, param);
	return ;
}
int close_window(void *param)
{
	t_tt	*tt;

	tt = (t_tt *)param;
	mlx_loop_end(tt->wd->mp);
	return (0);
}

int	move_person(int key, void *param)
{
	t_tt	*tt;
	t_cor	person;
	t_cor	exit;

	tt = (t_tt *)param;
	person = get_cor(tt->m_d, P);
	if (key == KEY_ESC)
		mlx_loop_end(tt->wd->mp);
	else
		move_way(key, person, tt);
	return (0);
}
int	move_way(int key, t_cor person, t_tt *tt)
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
	way.r += person.r;
	way.c += person.c;
	if (tt->m_d->c_map[way.r][way.c] == W)
		return (0);
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN || key == KEY_A || key == KEY_LEFT || key == KEY_D || key == KEY_RIGHT)
		printf("step : %d\n", tt->m_d->step++);
	if (tt->m_d->c_map[way.r][way.c] == C)
		tt->m_d->c_c--;
	if (tt->m_d->c_map[way.r][way.c] == E && tt->m_d->c_c == 0)
	{
		mlx_loop_end(tt->wd->mp);
		printf("!!!!!!!!!!!!!!!game clear!!!!!!!!!!!!!!!\n");
	}
	tt->m_d->c_map[person.r][person.c] = Z;
	if (get_cor(tt->m_d, E).r == -1)
		tt->m_d->c_map[tt->m_d->exit.r][tt->m_d->exit.c] = E;
	tt->m_d->c_map[way.r][way.c] = P;
	draw_map(tt);
}

void	destroy_tiles(t_tt *tt)
{
	mlx_destroy_image (tt->wd->mp, tt->t_d->ro);
	mlx_destroy_image (tt->wd->mp, tt->t_d->gr);
	mlx_destroy_image (tt->wd->mp, tt->t_d->pe);
	mlx_destroy_image (tt->wd->mp, tt->t_d->ch);
	mlx_destroy_image (tt->wd->mp, tt->t_d->dr);
}

int	end_game(t_tt *tt)
{
	int	rs;

	rs = tt->m_d->row_size;
	int c;
	c = is_proper_chars(tt->m_d);
	int a;
	a = is_square(tt->m_d);
	int b;
	if (a)
		b = is_w(tt->m_d);
	int d = tt->m_d->possible;
	if (a && b && c && d)
		destroy_tiles(tt);
	mlx_destroy_window(tt->wd->mp, tt->wd->wp);
	mlx_destroy_display(tt->wd->mp);
	if (a && b && c)
	{
		while (rs--)
			free(tt->m_d->c_map[rs]);
		free(tt->m_d->c_map);
		rs = tt->m_d->row_size;
		while (rs--)
			free(tt->m_d->vali_map[rs]);
		free(tt->m_d->vali_map);
	}
	free(tt->m_d->str);
	free(tt->m_d);
	if (a && b && c && d)
		free(tt->t_d);
	free(tt->wd->mp);
	free(tt->wd);
	free(tt);
	return (0);
}

