/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:00:14 by sanbaek          ###   ########.fr       */
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

int	move_person(int key, void *param)
{
	t_tt	*tt;
	t_c	person;
	t_c	exit;

	tt = (t_tt *)param;
	person = get_cor(tt->m_d, P);
	if (key == KEY_ESC)
		mlx_loop_end(tt->wd->mp);
	else
		move_way(key, person, tt);
	return (0);
}

int	move_way(int key, t_c person, t_tt *tt)
{
	t_c	way;

	way = get_way(key, person, way, tt);
	if (tt->m_d->cm[way.r][way.c] == W)
		return (0);
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN \
	|| key == KEY_A || key == KEY_LEFT || key == KEY_D || key == KEY_RIGHT)
		printf("step : %d\n", tt->m_d->step++);
	if (tt->m_d->cm[way.r][way.c] == C)
		tt->m_d->c_c--;
	if (tt->m_d->cm[way.r][way.c] == E && tt->m_d->c_c == 0)
	{
		mlx_loop_end(tt->wd->mp);
		printf("!!!!!!!!!!!!!!!game clear!!!!!!!!!!!!!!!\n");
	}
	tt->m_d->cm[person.r][person.c] = Z;
	if (get_cor(tt->m_d, E).r == -1)
		tt->m_d->cm[tt->m_d->exit.r][tt->m_d->exit.c] = E;
	tt->m_d->cm[way.r][way.c] = P;
	draw_map(tt);
}

t_c	get_way(int key, t_c person, t_c way, t_tt *tt)
{
	way = (t_c){0, 0};
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
	return (way);
}
