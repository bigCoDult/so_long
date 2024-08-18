/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:38:26 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:14:04 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_t *t)
{
	int	rs;
	int	a;
	int	b;
	int	c;
	int	d;

	rs = t->m_d->row_size;
	a = is_square(t->m_d);
	if (a)
		b = is_w(t->m_d);
	c = is_proper_chars(t->m_d);
	d = t->m_d->possible;
	if (a && b && c && d)
		destroy_tiles(t);
	mlx_destroy_window(t->wd->mp, t->wd->wp);
	mlx_destroy_display(t->wd->mp);
	if (a && b && c)
		free_maps(t->m_d, rs);
	free(t->m_d->str);
	free(t->m_d);
	if (a && b && c && d)
		free(t->td);
	free(t->wd->mp);
	free(t->wd);
	free(t);
	return (0);
}
int free_maps(t_m_d *m_d, int rs)
	{
		while (rs--)
			free(m_d->cm[rs]);
		free(m_d->cm);
		rs = m_d->row_size;
		while (rs--)
			free(m_d->vm[rs]);
		free(m_d->vm);
}

int	close_window(void *param)
{
	t_t	*t;

	t = (t_t *)param;
	mlx_loop_end(t->wd->mp);
	return (0);
}

void	destroy_tiles(t_t *t)
{
	mlx_destroy_image (t->wd->mp, t->td->r);
	mlx_destroy_image (t->wd->mp, t->td->g);
	mlx_destroy_image (t->wd->mp, t->td->p);
	mlx_destroy_image (t->wd->mp, t->td->h);
	mlx_destroy_image (t->wd->mp, t->td->d);
}
