/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:36:53 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:01:47 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_c	get_cor(t_m_d *m_d, char c)
{
	t_c	person;

	person = (t_c){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < m_d->row_size)
	{
		person.c = 0;
		while (person.c < m_d->col_size)
		{
			if (m_d->cm[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return ((t_c){-1, -1});
}

void	draw_map(t_tt	*tt)
{
	int		index;
	t_c	c;

	index = 0;
	c = (t_c){0, 0};
	while (c.r < tt->m_d->row_size)
	{
		c.c = 0;
		while (c.c < tt->m_d->col_size)
		{
			if (tt->m_d->cm[c.r][c.c] == W)
				pi(tt->wd->mp, tt->wd->wp, tt->td->ro, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == Z)
				pi(tt->wd->mp, tt->wd->wp, tt->td->gr, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == P)
				pi(tt->wd->mp, tt->wd->wp, tt->td->pe, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == C)
				pi(tt->wd->mp, tt->wd->wp, tt->td->ch, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == E)
				pi(tt->wd->mp, tt->wd->wp, tt->td->dr, (t_c){T * c.c++, T * c.r});
		}
		c.r++;
	}
}

void	pi(void *mlx, void *win, void *img, t_c c)
{
	mlx_put_image_to_window(mlx, win, img, c.r, c.c);
}

void	*init_tiles(t_tt	*tt)
{
	tt->td = malloc(sizeof(t_t_d));
	if (tt->td == NULL)
		return (NULL);
	tt->td->ro = open_xpm(tt->wd, NULL, "rock");
	tt->td->gr = open_xpm(tt->wd, NULL, "grass");
	tt->td->pe = open_xpm(tt->wd, NULL, "person");
	tt->td->ch = open_xpm(tt->wd, NULL, "chest");
	tt->td->dr = open_xpm(tt->wd, NULL, "door");
	return (NULL);
}
