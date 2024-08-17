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
	t_tt	*tt;

	tt = malloc(sizeof(t_tt));
	if (tt == NULL)
		return ;
	tt->wd = malloc(sizeof(t_wd));
	if (tt->wd == NULL)
		return ;
	tt->m_d = malloc(sizeof(t_m_d));
	if (tt->m_d == NULL)
		return ;
	tt->m_d->row_size = 0;
	tt->m_d->col_size = 0;
	set_str(fd, tt->m_d);
	init_wd(tt);
	if (deal_map(tt))
		key_hook(tt);
	mlx_loop(tt->wd->mp);
	end_game(tt);
}

int	deal_map(t_tt	*tt)
{
	t_cor	person;

	if (!validate_map(tt->m_d))
	{
		mlx_loop_end(tt->wd->mp);
		return (0);
	}
	set_c_map(tt->m_d);
	set_v_map(tt->m_d);
	person = get_cor(tt->m_d, P);
	tt->m_d->possible = is_possible(tt->m_d, person);
	if (!tt->m_d->possible)
	{
		printf("[impossible map]\n");
		mlx_loop_end(tt->wd->mp);
		return (0);
	}
	init_tiles(tt);
	return (1);
}

void	init_wd(t_tt *tt)
{
	tt->wd->title = "so_long";
	tt->wd->size_x = tt->m_d->col_size * 20;
	tt->wd->size_y = tt->m_d->row_size * 20;
	tt->wd->mp = mlx_init();
	tt->wd->wp = mlx_new_window(\
	tt->wd->mp, tt->wd->size_x, tt->wd->size_y, tt->wd->title);
	return ;
}
