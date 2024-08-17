/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:39:20 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/17 12:14:52 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(t_tot *tot)
{
	void	*param;
	int		step;

	step = 0;
	tot->m_d->step = 0;
	printf("step : %d\n", tot->m_d->step++);
	draw_map(tot);
	tot->m_d->exit = get_cor(tot->m_d, E);
	param = (void *)tot;
	is_proper_chars(tot->m_d);
	mlx_key_hook(tot->w_d->w_p, &move_person, param);
	return ;
}

int	move_person(int key, void *param)
{
	t_tot	*tot;
	t_cor	person;
	t_cor	exit;

	tot = (t_tot *)param;
	person = get_cor(tot->m_d, P);
	if (key == KEY_ESC)
		mlx_loop_end(tot->w_d->m_p);
	else
		move_way(key, person, tot);
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
	way.r += person.r;
	way.c += person.c;
	if (tot->m_d->c_map[way.r][way.c] == W)
		return (0);
	if (key == KEY_W || key == KEY_UP || key == KEY_S || key == KEY_DOWN || key == KEY_A || key == KEY_LEFT || key == KEY_D || key == KEY_RIGHT)
		printf("step : %d\n", tot->m_d->step++);
	if (tot->m_d->c_map[way.r][way.c] == C)
		tot->m_d->c_c--;
	if (tot->m_d->c_map[way.r][way.c] == E && tot->m_d->c_c == 0)
	{
		mlx_loop_end(tot->w_d->m_p);
		printf("!!!!!!!!!!!!!!!game clear!!!!!!!!!!!!!!!\n");
	}
	tot->m_d->c_map[person.r][person.c] = Z;
	if (get_cor(tot->m_d, E).r == -1)
		tot->m_d->c_map[tot->m_d->exit.r][tot->m_d->exit.c] = E;
	tot->m_d->c_map[way.r][way.c] = P;
	draw_map(tot);
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
	int c;
	c = is_proper_chars(tot->m_d);
	int a;
	a = is_square(tot->m_d);
	int b;
	if (a)
		b = is_w(tot->m_d);
	int d = tot->m_d->possible;
	if (a && b && c && d)
		destroy_tiles(tot);
	mlx_destroy_window(tot->w_d->m_p, tot->w_d->w_p);
	mlx_destroy_display(tot->w_d->m_p);
	if (a && b && c)
	{
		while (rs--)
			free(tot->m_d->c_map[rs]);
		free(tot->m_d->c_map);
		rs = tot->m_d->row_size;
		while (rs--)
			free(tot->m_d->vali_map[rs]);
		free(tot->m_d->vali_map);
	}
	free(tot->m_d->str);
	free(tot->m_d);
	if (a && b && c && d)
		free(tot->t_d);
	free(tot->w_d->m_p);
	free(tot->w_d);
	free(tot);
	return (0);
}

