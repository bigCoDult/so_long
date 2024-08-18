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
	t_t	*t;

	t = malloc(sizeof(t_t));
	if (t == NULL)
		return ;
	t->wd = malloc(sizeof(t_wd));
	if (t->wd == NULL)
		return ;
	t->m_d = malloc(sizeof(t_m_d));
	if (t->m_d == NULL)
		return ;
	t->m_d->row_size = 0;
	t->m_d->col_size = 0;
	set_str(fd, t->m_d);
	init_wd(t);
	if (deal_map(t))
		key_hook(t);
	mlx_loop(t->wd->mp);
	end_game(t);
}

int	deal_map(t_t	*t)
{
	t_c	person;

	if (!validate_map(t->m_d))
	{
		mlx_loop_end(t->wd->mp);
		return (0);
	}
	set_c_map(t->m_d);
	set_v_map(t->m_d);
	person = get_cor(t->m_d, P);
	t->m_d->possible = is_possible(t->m_d, person);
	if (!t->m_d->possible)
	{
		printf("[impossible map]\n");
		mlx_loop_end(t->wd->mp);
		return (0);
	}
	init_tiles(t);
	return (1);
}

void	init_wd(t_t *t)
{
	t->wd->title = "so_long";
	t->wd->size_x = t->m_d->col_size * 20;
	t->wd->size_y = t->m_d->row_size * 20;
	t->wd->mp = mlx_init();
	t->wd->wp = mlx_new_window(\
	t->wd->mp, t->wd->size_x, t->wd->size_y, t->wd->title);
	return ;
}
