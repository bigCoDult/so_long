/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:36:53 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:15:38 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_c	get_cor(t_md *md, char c)
{
	t_c	person;

	person = (t_c){0, 0};
	person.r = 0;
	person.c = 0;
	while (person.r < md->row_size)
	{
		person.c = 0;
		while (person.c < md->col_size)
		{
			if (md->cm[person.r][person.c] == c)
				return (person);
			person.c++;
		}
		person.r++;
	}
	return ((t_c){-1, -1});
}

void	draw_map(t_t	*t)
{
	int	index;
	t_c	c;

	index = 0;
	c = (t_c){0, 0};
	while (c.r < t->md->row_size)
	{
		c.c = 0;
		while (c.c < t->md->col_size)
		{
			if (t->md->cm[c.r][c.c] == W)
				pi(t->wd->mp, t->wd->wp, t->td->r, (t_c){T * c.c++, T * c.r});
			else if (t->md->cm[c.r][c.c] == Z)
				pi(t->wd->mp, t->wd->wp, t->td->g, (t_c){T * c.c++, T * c.r});
			else if (t->md->cm[c.r][c.c] == P)
				pi(t->wd->mp, t->wd->wp, t->td->p, (t_c){T * c.c++, T * c.r});
			else if (t->md->cm[c.r][c.c] == C)
				pi(t->wd->mp, t->wd->wp, t->td->h, (t_c){T * c.c++, T * c.r});
			else if (t->md->cm[c.r][c.c] == E)
				pi(t->wd->mp, t->wd->wp, t->td->d, (t_c){T * c.c++, T * c.r});
		}
		c.r++;
	}
}

void	pi(void *mlx, void *win, void *img, t_c c)
{
	mlx_put_image_to_window(mlx, win, img, c.r, c.c);
}

void	*init_tiles(t_t	*t)
{
	t->td = malloc(sizeof(t_t_d));
	if (t->td == NULL)
		return (NULL);
	t->td->r = open_xpm(t->wd, NULL, "rock");
	t->td->g = open_xpm(t->wd, NULL, "grass");
	t->td->p = open_xpm(t->wd, NULL, "person");
	t->td->h = open_xpm(t->wd, NULL, "chest");
	t->td->d = open_xpm(t->wd, NULL, "door");
	return (NULL);
}
