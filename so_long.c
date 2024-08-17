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

t_cor	get_cor(t_m_d *m_d, char c)
{
	t_cor	person;

	person = (t_cor){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < m_d->row_size)
	{
		person.c = 0;
		while (person.c < m_d->col_size)
		{
			if (m_d->c_map[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return ((t_cor){-1, -1});
}

void	draw_map(t_tt	*tt)
{
	int		index;
	t_cor	c;

	index = 0;
	c = (t_cor){0, 0};
	while (c.r < tt->m_d->row_size)
	{
		c.c = 0;
		while (c.c < tt->m_d->col_size)
		{
			if (tt->m_d->c_map[c.r][c.c] == W)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->ro, TL * c.c++, TL * c.r);
				// pi(tt->wd->mp, tt->wd->wp, tt->t_d->ro, &(t_cor){TL * c.c++, TL * c.r});
			else if (tt->m_d->c_map[c.r][c.c] == Z)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->gr, TL * c.c++, TL * c.r);
			else if (tt->m_d->c_map[c.r][c.c] == P)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->pe, TL * c.c++, TL * c.r);
			else if (tt->m_d->c_map[c.r][c.c] == C)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->ch, TL * c.c++, TL * c.r);
			else if (tt->m_d->c_map[c.r][c.c] == E)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->dr, TL * c.c++, TL * c.r);
		}
		c.r++;
	}
}

void	pi(void *mlx, void *win, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img, x, y);
}

void	*init_tiles(t_tt	*tt)
{
	tt->t_d = malloc(sizeof(t_t_d));
	if (tt->t_d == NULL)
		return (NULL);
	tt->t_d->ro = open_xpm(tt->wd, NULL, "rock");
	tt->t_d->gr = open_xpm(tt->wd, NULL, "grass");
	tt->t_d->pe = open_xpm(tt->wd, NULL, "person");
	tt->t_d->ch = open_xpm(tt->wd, NULL, "chest");
	tt->t_d->dr = open_xpm(tt->wd, NULL, "door");
	return (NULL);
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
