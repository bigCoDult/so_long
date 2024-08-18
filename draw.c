/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:36:53 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:04:23 by sanbaek          ###   ########.fr       */
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
	int	index;
	t_c	c;

	index = 0;
	c = (t_c){0, 0};
	while (c.r < tt->m_d->row_size)
	{
		c.c = 0;
		while (c.c < tt->m_d->col_size)
		{
			if (tt->m_d->cm[c.r][c.c] == W)
				pi(tt->wd->mp, tt->wd->wp, tt->td->r, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == Z)
				pi(tt->wd->mp, tt->wd->wp, tt->td->g, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == P)
				pi(tt->wd->mp, tt->wd->wp, tt->td->p, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == C)
				pi(tt->wd->mp, tt->wd->wp, tt->td->h, (t_c){T * c.c++, T * c.r});
			else if (tt->m_d->cm[c.r][c.c] == E)
				pi(tt->wd->mp, tt->wd->wp, tt->td->d, (t_c){T * c.c++, T * c.r});
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
	tt->td->r = open_xpm(tt->wd, NULL, "rock");
	tt->td->g = open_xpm(tt->wd, NULL, "grass");
	tt->td->p = open_xpm(tt->wd, NULL, "person");
	tt->td->h = open_xpm(tt->wd, NULL, "chest");
	tt->td->d = open_xpm(tt->wd, NULL, "door");
	return (NULL);
}
