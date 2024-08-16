/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:51:06 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/16 13:51:06 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	fd = open("map.ber", O_RDONLY);
	so_long(fd);
	close(fd);
	return (0);
}

void	so_long(int fd)
{
	t_tot	*tot;

	tot = malloc(sizeof(t_tot));
	if (tot == NULL)
		return ;
	tot->w_d = malloc(sizeof(t_w_d));
	if (tot->w_d == NULL)
		return ;
	tot->map_d = malloc(sizeof(t_m_d));
	if (tot->map_d == NULL)
		return ;
	tot->map_d->vali_map = set_str(fd, tot->map_d);
	init_w_d(tot);
	deal_map(tot);
	key_hook(tot);
	mlx_loop(tot->w_d->m_p);
	// mlx_hook(tot->w_d->w_p, 17, 0, end_game, tot);
		// 게임 종료
		// 안되는디?
	end_game(tot);
}

void	init_w_d(t_tot *tot)
{
	tot->w_d->title = "so_long";
	tot->w_d->size_x = tot->map_d->col_size * 20;
	tot->w_d->size_y = tot->map_d->row_size * 20;
	tot->w_d->m_p = mlx_init();
	tot->w_d->w_p = mlx_new_window(\
	tot->w_d->m_p, tot->w_d->size_x, tot->w_d->size_y, tot->w_d->title);
	return ;
}

t_cor	get_cor(t_m_d *map_d, char c)
{
	t_cor	person;

	person = (t_cor){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < map_d->row_size)
	{
		person.c = 0;
		while (person.c < map_d->col_size)
		{
			if (map_d->c_map[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return ((t_cor){-1, -1});
}

void	draw_map(t_tot	*tot)
{
	int		index;
	t_cor	cor;

	index = 0;
	cor = (t_cor){0, 0};
	while (cor.r < tot->map_d->row_size)
	{
		cor.c = 0;
		while (cor.c < tot->map_d->col_size)
		{
			if (tot->map_d->c_map[cor.r][cor.c] == W)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->rock, T_L * cor.c++, T_L * cor.r);
			else if (tot->map_d->c_map[cor.r][cor.c] == Z)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->grass, T_L * cor.c++, T_L * cor.r);
			else if (tot->map_d->c_map[cor.r][cor.c] == P)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->person, T_L * cor.c++, T_L * cor.r);
			else if (tot->map_d->c_map[cor.r][cor.c] == C)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->chest, T_L * cor.c++, T_L * cor.r);
			else if (tot->map_d->c_map[cor.r][cor.c] == E)
				mlx_put_image_to_window (tot->w_d->m_p, tot->w_d->w_p, \
				tot->t_d->door, T_L * cor.c++, T_L * cor.r);
		}
		cor.r++;
	}
}