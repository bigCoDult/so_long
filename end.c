/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:38:26 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 09:04:23 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_tt *tt)
{
	int	rs;
	int	a;
	int	b;
	int	c;
	int	d;

	rs = tt->m_d->row_size;
	a = is_square(tt->m_d);
	if (a)
		b = is_w(tt->m_d);
	c = is_proper_chars(tt->m_d);
	d = tt->m_d->possible;
	if (a && b && c && d)
		destroy_tiles(tt);
	mlx_destroy_window(tt->wd->mp, tt->wd->wp);
	mlx_destroy_display(tt->wd->mp);
	if (a && b && c)
	{
		while (rs--)
			free(tt->m_d->cm[rs]);
		free(tt->m_d->cm);
		rs = tt->m_d->row_size;
		while (rs--)
			free(tt->m_d->vm[rs]);
		free(tt->m_d->vm);
	}
	free(tt->m_d->str);
	free(tt->m_d);
	if (a && b && c && d)
		free(tt->td);
	free(tt->wd->mp);
	free(tt->wd);
	free(tt);
	return (0);
}

int	close_window(void *param)
{
	t_tt	*tt;

	tt = (t_tt *)param;
	mlx_loop_end(tt->wd->mp);
	return (0);
}

void	destroy_tiles(t_tt *tt)
{
	mlx_destroy_image (tt->wd->mp, tt->td->r);
	mlx_destroy_image (tt->wd->mp, tt->td->g);
	mlx_destroy_image (tt->wd->mp, tt->td->p);
	mlx_destroy_image (tt->wd->mp, tt->td->h);
	mlx_destroy_image (tt->wd->mp, tt->td->d);
}
