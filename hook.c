/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:30:14 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_t *t)
{
	void	*param;
	int		step;

	step = 0;
	t->md->step = 0;
	printf("step : %d\n", t->md->step++);
	draw_map(t);
	t->md->exit = get_cor(t->md, E);
	param = (void *)t;
	is_proper_chars(t->md);
	mlx_hook(t->wd->wp, KeyPress, KeyPressMask, &move_person, param);
	mlx_hook(t->wd->wp, DestroyNotify, NoEventMask, &close_window, param);
	return ;
}

int	move_person(int key, void *param)
{
	t_t	*t;
	t_c	person;
	t_c	exit;

	t = (t_t *)param;
	person = get_cor(t->md, P);
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
	if (t->md->cm[way.r][way.c] == W)
		return (0);
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN \
	|| key == KEY_A || key == KEY_LEFT || key == KEY_D || key == KEY_RIGHT)
		printf("step : %d\n", t->md->step++);
	if (t->md->cm[way.r][way.c] == C)
		t->md->c_c--;
	if (t->md->cm[way.r][way.c] == E && t->md->c_c == 0)
	{
		mlx_loop_end(t->wd->mp);
		printf("!!!!!!!!!!!!!!!game clear!!!!!!!!!!!!!!!\n");
	}
	t->md->cm[person.r][person.c] = Z;
	if (get_cor(t->md, E).r == -1)
		t->md->cm[t->md->exit.r][t->md->exit.c] = E;
	t->md->cm[way.r][way.c] = P;
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
