/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:38:26 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 08:38:26 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_tt *tt)
{
	int	rs;

	rs = tt->m_d->row_size;
	int c;
	c = is_proper_chars(tt->m_d);
	int a;
	a = is_square(tt->m_d);
	int b;
	if (a)
		b = is_w(tt->m_d);
	int d = tt->m_d->possible;
	if (a && b && c && d)
		destroy_tiles(tt);
	mlx_destroy_window(tt->wd->mp, tt->wd->wp);
	mlx_destroy_display(tt->wd->mp);
	if (a && b && c)
	{
		while (rs--)
			free(tt->m_d->c_map[rs]);
		free(tt->m_d->c_map);
		rs = tt->m_d->row_size;
		while (rs--)
			free(tt->m_d->vali_map[rs]);
		free(tt->m_d->vali_map);
	}
	free(tt->m_d->str);
	free(tt->m_d);
	if (a && b && c && d)
		free(tt->t_d);
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
	mlx_destroy_image (tt->wd->mp, tt->t_d->ro);
	mlx_destroy_image (tt->wd->mp, tt->t_d->gr);
	mlx_destroy_image (tt->wd->mp, tt->t_d->pe);
	mlx_destroy_image (tt->wd->mp, tt->t_d->ch);
	mlx_destroy_image (tt->wd->mp, tt->t_d->dr);
}
