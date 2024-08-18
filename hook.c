/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:06:07 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_t *t)
{
	void	*param;
	int		step;

	step = 0;
	t->m_d->step = 0;
	printf("step : %d\n", t->m_d->step++);
	draw_map(t);
	t->m_d->exit = get_cor(t->m_d, E);
	param = (void *)t;
	is_proper_chars(t->m_d);
	mlx_hook(t->wd->wp, KeyPress, KeyPressMask, &move_person, param);
	mlx_hook(t->wd->wp, 17, NoEventMask, &close_window, param);
	return ;
}

int	move_person(int key, void *param)
{
	t_t	*t;
	t_c	person;
	t_c	exit;

	t = (t_t *)param;
	person = get_cor(t->m_d, P);
	if (key == KEY_ESC)
		mlx_loop_end(t->wd->mp);
	else
		move_way(key, person, t);
	return (0);
}

int	move_way(int key, t_c person, t_t *t)
{
	t_c	way;

	way = get_way(key, person, way, t);
	if (t->m_d->cm[way.r][way.c] == W)
		return (0);
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN \
	|| key == KEY_A || key == KEY_LEFT || key == KEY_D || key == KEY_RIGHT)
		printf("step : %d\n", t->m_d->step++);
	if (t->m_d->cm[way.r][way.c] == C)
		t->m_d->c_c--;
	if (t->m_d->cm[way.r][way.c] == E && t->m_d->c_c == 0)
	{
		mlx_loop_end(t->wd->mp);
		printf("!!!!!!!!!!!!!!!game clear!!!!!!!!!!!!!!!\n");
	}
	t->m_d->cm[person.r][person.c] = Z;
	if (get_cor(t->m_d, E).r == -1)
		t->m_d->cm[t->m_d->exit.r][t->m_d->exit.c] = E;
	t->m_d->cm[way.r][way.c] = P;
	draw_map(t);
}

t_c	get_way(int key, t_c person, t_c way, t_t *t)
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
