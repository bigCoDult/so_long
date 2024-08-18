/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:38:26 by sanbaek           #+#    #+#             */
/*   Updated: 2024/08/18 11:35:34 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_t *t)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = is_square(t->md);
	if (a)
		b = is_wall(t->md);
	c = is_proper_chars(t->md);
	d = t->md->possible;
	if (a && b && c && d)
		destroy_tiles(t);
	mlx_destroy_window(t->wd->mp, t->wd->wp);
	mlx_destroy_display(t->wd->mp);
	if (a && b && c)
		free_maps(t->md);
	free(t->md->str);
	free(t->md);
	if (a && b && c && d)
		free(t->td);
	free(t->wd->mp);
	free(t->wd);
	free(t);
	return (0);
}

int	free_maps(t_md *md)
{
	int	rs;

	rs = md->row_size;
	while (rs--)
		free(md->cm[rs]);
	free(md->cm);
	rs = md->row_size;
	while (rs--)
		free(md->vm[rs]);
	free(md->vm);
	return (0);
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

int	is_llaw(t_md *md, int i, int fst_l)
{
	while (md->str[i] != '\0')
	{
		i++;
		if (md->str[i] != W || md->str[i + fst_l - 1] != W)
			return (0);
		i += fst_l;
	}
	while (md->str[i] != '\0')
		i++;
	i -= fst_l;
	while (fst_l--)
	{
		if (md->str[i] != W)
			return (0);
		i++;
	}
	if (md->str[i] != '\0')
		return (0);
	return (1);
}
