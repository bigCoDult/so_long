/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:36:53 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 08:52:54 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				// pi(tt->wd->mp, tt->wd->wp, tt->t_d->ro, (t_cor){TL * c.c++, TL * c.r});
			else if (tt->m_d->c_map[c.r][c.c] == Z)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->gr, TL * c.c++, TL * c.r);
				// pi(tt->wd->mp, tt->wd->wp, tt->t_d->gr, (t_cor){TL * c.c++, TL * c.r});
			else if (tt->m_d->c_map[c.r][c.c] == P)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->pe, TL * c.c++, TL * c.r);
				// pi(tt->wd->mp, tt->wd->wp, tt->t_d->pe, (t_cor){TL * c.c++, TL * c.r});
			else if (tt->m_d->c_map[c.r][c.c] == C)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->ch, TL * c.c++, TL * c.r);
				// pi(tt->wd->mp, tt->wd->wp, tt->t_d->ch, (t_cor){TL * c.c++, TL * c.r});
			else if (tt->m_d->c_map[c.r][c.c] == E)
				pi(tt->wd->mp, tt->wd->wp, tt->t_d->dr, TL * c.c++, TL * c.r);
				// pi(tt->wd->mp, tt->wd->wp, tt->t_d->dr, (t_cor){TL * c.c++, TL * c.r});
		}
		c.r++;
	}
}

void	pi(void *mlx, void *win, void *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img, x, y);
}
// void	pi(void *mlx, void *win, void *img, t_cor c)
// {
// 	mlx_put_image_to_window(mlx, win, img, c.c, c.r);
// }

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
